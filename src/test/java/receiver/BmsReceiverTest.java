package receiver;

import static org.junit.Assert.assertTrue;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.List;

import org.junit.Before;
import org.junit.Test;
import main.java.receiver.BmsReceiverTask;
import main.java.receiver.NoDataReceivedException;
public class BmsReceiverTest {

	private final ByteArrayOutputStream outputStreamCaptor = new ByteArrayOutputStream();

	@Before
	public void setup() {
		System.setOut(new PrintStream(outputStreamCaptor));
	}

	@Test(expected = NoDataReceivedException.class)
	public void givenEmptyListPassedWhenGetMaxMin_thenThrowsNoDataFoundException() throws NoDataReceivedException {
		// when
		String paramName = "SOC";
		Double[] valueArray = {};
		List<Double> valueList = Arrays.asList(valueArray);
		// then
		BmsReceiverTask.getMaxAndMinValueOfIncomingParameters(paramName, valueList);
	}

	@Test
	public void givenvalueListPassedWhenGetMaxMin_thenOutPutIsPrintedOnConsole() throws NoDataReceivedException {
		// when
		String paramName = "SOC";
		Double[] valueArray = { 23.67, 34.78, 10.67, 90.34, 90.43 };
		List<Double> valueList = Arrays.asList(valueArray);
		// then
		BmsReceiverTask.getMaxAndMinValueOfIncomingParameters(paramName, valueList);
		// verify
		assertTrue(outputStreamCaptor.toString().trim().equals("SOC : Max, Min = 90.43,10.67"));
	}

	@Test(expected = NoDataReceivedException.class)
	public void givenNullValuePassedWhenGetMaxMin_thenOutPutIsPrintedOnConsole() throws NoDataReceivedException {
		// then
		BmsReceiverTask.getMaxAndMinValueOfIncomingParameters(null, null);
	}

	@Test
	public void givenEmptyListPassedWhenGetSma_thenThrowsNoDataFoundException() throws NoDataReceivedException {
		// when
		String paramName = "SOC";
		Double[] valueArray = {};
		List<Double> valueList = Arrays.asList(valueArray);
		// then
		BmsReceiverTask.getSmaOfParamValues(paramName, valueList);
		assertTrue(outputStreamCaptor.toString().trim().equals(""));
	}

	@Test
	public void givenValueListPassedWhenGetSma_thenOutPutIsPrintedOnConsole() throws NoDataReceivedException {
		// when
		String paramName = "SOC";
		Double[] valueArray = { 23.67, 34.78, 10.67, 90.34, 90.43, 89.80, 23.89 };
		List<Double> valueList = Arrays.asList(valueArray);
		// then
		BmsReceiverTask.getSmaOfParamValues(paramName, valueList);
		// verify
		assertTrue(outputStreamCaptor.toString().trim().equals("Simple moving average of SOC = 61.03"));
	}

	@Test(expected = NoDataReceivedException.class)
	public void givenNullValuePassedWhenGetSma_thenOutPutIsPrintedOnConsole() throws NoDataReceivedException {
		// then
		BmsReceiverTask.getSmaOfParamValues(null, null);
	}

	@Test
	public void givenNullValuePassedWhenPrintSma_thenOutPutIsPrintedOnConsole() throws NoDataReceivedException {
		// then
		BmsReceiverTask.printSmaOfParamValues(null, null);
		// verify
		assertTrue(outputStreamCaptor.toString().trim().equals("Simple moving average of null = nu"));
	}

}
