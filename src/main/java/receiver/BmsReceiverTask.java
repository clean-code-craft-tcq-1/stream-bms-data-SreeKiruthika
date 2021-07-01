package main.java.receiver;

import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

public class BmsReceiverTask {
	/**
	 * sending each parameter to determine some data like max, min etc.
	 * 
	 * @param paramMap
	 */
	static void performOperationsOnParamMap(HashMap<String, List<Double>> paramMap) {
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
			Double sma = paramValueList.subList(paramValueList.size() - 5, paramValueList.size()).stream()
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
