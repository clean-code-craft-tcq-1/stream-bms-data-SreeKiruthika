#include "bms.h"

/****************************************************************************************
*Func desc : This function is to print the passed BMS data to console - stubbed
*Param     : BMSDataArray - Float array pointer which holds the BMS data
			 arraySize    - Size of array passed
*Return    : None
*****************************************************************************************/
void printToConsole(float * BMSDataArray , int arraySize)
{

   WriteFormatted("%0.2f;%0.2f\n", BMSDataArray[0], BMSDataArray[1]);

   validatePrintedOutput();	
}

/****************************************************************************************
*Func desc : This function is to fetch the BMS temperature value (can be from file or database) - Faked
*Param     : None
*Return    : Returns Temperature value - Float type
*****************************************************************************************/

float getBMSTemperatue()
{
	static int i=0;
	if (i >= MAX_PRINT)
	{
		TemperatureInputTest = EOF;
	}
	else
	{
	    TemperatureInputTest = RandomFloatGeneratorWithinRange(TEMP_MIN, TEMP_MAX);
	}
	
	i++;
   
    return TemperatureInputTest;
}

/****************************************************************************************
*Func desc : This function is to fetch the BMS charge rate value (can be from file or database) - Faked
*Param     : None
*Return    : Returns Temperature value - Float type
*****************************************************************************************/

float getBMSChargeRate()
{
	static int i=0;
   
    if (i >= MAX_PRINT)
	{
		ChargeRateInputTest = EOF;
	}
	else
	{
	    ChargeRateInputTest = RandomFloatGeneratorWithinRange(CHRGRATE_MIN, CHRGRATE_MAX) ;
	}
	
	i++;
	
    return ChargeRateInputTest;
}