package main.java.receiver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
public class BmsReceiver {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("----- Reading input from sender started -------");
		HashMap<String, List<Double>> paramMap = new HashMap<>();
		try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
			// to create the list of parameter names coming from sender
			List<String> parametersList = Arrays.asList(reader.readLine().split(";"));
			paramMap = prepareParamMap(parametersList);
			readAndPerformOpronDataFromSender(reader, parametersList, paramMap);
		} catch (IOException e) {
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
	private static void readAndPerformOpronDataFromSender(BufferedReader reader, List<String> parametersList,
			HashMap<String, List<Double>> paramMap) throws IOException {
		String line = null;
		while (true) {
			line = reader.readLine();
			if (!line.equals("-1.00;-1.00")) {
				System.out.print("\r");
				fillParamMapListWithSenderData(parametersList, paramMap, line);
				BmsReceiverTask.performOperationsOnParamMap(paramMap);
			} else {
				break;
			}
		}
	}

	private static void fillParamMapListWithSenderData(List<String> parametersList,
			HashMap<String, List<Double>> paramMap, String line) {
		String[] param = line.split(";");
		// to add newly read paramter into the list
		for (int i = 0; i < param.length; i++) {
			paramMap.get(parametersList.get(i)).add(Double.parseDouble(param[i]));
		}
	}
}
