package receiver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

public class BmsReceiver {

	public static void main(String[] args) {
		System.out.println("----- Reading input from sender started -------");
		HashMap<String, List<Double>> paramMap = new HashMap<>();
		try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
			String line = null;
			// to create the list of parameter names coming from sender
			List<String> parametersList = Arrays.asList(reader.readLine().split(";"));
			paramMap = prepareParamMap(parametersList);
			readAndPrintDataFromSender(reader, parametersList, paramMap);
		} catch (Exception e) {
			System.err.println(e);
		}
	}

	/*
	 * to add entries in map that will contain parameter name as key and it's values
	 * list as value
	 * 
	 * @param parametersList
	 * 
	 * @return
	 */
	private static HashMap<String, List<Double>> prepareParamMap(List<String> parametersList) {
		HashMap<String, List<Double>> paramMap = new HashMap<>();
		parametersList.forEach(param -> {
			paramMap.put(param, new ArrayList<>());
		});
		return paramMap;
	}

	/**
	 * @param reader
	 * @param parametersList
	 * @param paramMap
	 * @throws NumberFormatException
	 * @throws IOException
	 * @throws InterruptedException
	 */
	private static void readAndPrintDataFromSender(BufferedReader reader, List<String> parametersList,
			HashMap<String, List<Double>> paramMap) throws NumberFormatException, IOException, InterruptedException {
		String line = null;
		while (true) {
			if ((line = reader.readLine()) != null && !line.equals("-1.00;-1.00")) {
				System.out.print("\r");
				String[] param = line.split(";");
				// to add newly read paramter into the list
				for (int i = 0; i < param.length; i++) {
					paramMap.get(parametersList.get(i)).add(Double.parseDouble(param[i]));
				}
				performOperationsOnParamMap(paramMap);
			} else {
				break;
			}
			Thread.sleep(500);
		}
	}

	/**
	 * sending each parameter to determine some data like max, min etc.
	 * 
	 * @param paramMap
	 */
	private static void performOperationsOnParamMap(HashMap<String, List<Double>> paramMap) {
		paramMap.forEach((paramName, valueList) -> {
			try {
				getMaxAndMinValueOfIncomingParameters(paramName, valueList);
				getSmaOfParamValues(paramName, valueList);
			} catch (NoDataReceivedException e) {
				System.err.println(e);
			}

		});
	}

	/**
	 * to get maximum and minimum values among all the parameter values read till
	 * now
	 * 
	 * @param paramName
	 * @param paramValueList
	 * @throws NoDataReceivedException
	 */
	public static void getMaxAndMinValueOfIncomingParameters(String paramName, List<Double> paramValueList)
			throws NoDataReceivedException {
		try {
			Double maxVal = paramValueList.stream().sorted().collect(Collectors.toList())
					.get(paramValueList.size() - 1);
			Double minVal = paramValueList.stream().sorted().collect(Collectors.toList()).get(0);
			printMaxAndMinValueOfIncomingParameters(paramName, maxVal, minVal);
		} catch (ArrayIndexOutOfBoundsException | NullPointerException e) {
			throw new NoDataReceivedException();
		}
	}

	/**
	 * to print the maximum and minimum values among all the parameter values read
	 * till now, on the console
	 * 
	 * @param paramName
	 * @param maxVal
	 * @param minVal
	 */
	public static void printMaxAndMinValueOfIncomingParameters(String paramName, Double maxVal, Double minVal) {
		System.out.print(paramName + " : Max, Min = " + String.format("%.2f", maxVal) + ","
				+ String.format("%.2f", minVal) + "\t");
	}

	/**
	 * to get simple moving average of last five values of parameters
	 * 
	 * @param paramName
	 * @param paramValueList
	 * @throws NoDataReceivedException
	 */
	public static void getSmaOfParamValues(String paramName, List<Double> paramValueList)
			throws NoDataReceivedException {
		try {
			Double sma = paramValueList.subList(paramValueList.size() - 5, paramValueList.size() - 1).stream()
					.mapToDouble(i -> i).average().orElse(0);
			printSmaOfParamValues(paramName, sma);
		} catch (IndexOutOfBoundsException e) {
			// exception will occur if list length is less than 5
		} catch (NullPointerException e) {
			throw new NoDataReceivedException();
		}
	}

	/**
	 * to print the simple moving average of last 5 parameter values read till now,
	 * on the console
	 * 
	 * @param paramName
	 * @param sma
	 */
	public static void printSmaOfParamValues(String paramName, Double sma) {
		System.out.print("Simple moving average of " + paramName + " = " + String.format("%.2f", sma) + "\t");
	}
}