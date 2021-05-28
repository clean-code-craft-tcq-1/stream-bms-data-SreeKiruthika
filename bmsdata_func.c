#include "bms.h"

void printToConsole(float * BMSDataArray , int arraySize)
{

   WriteFormatted("%0.2f;%0.2f\n", BMSDataArray[0], BMSDataArray[1]);

   validatePrintedOutput();	
}


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