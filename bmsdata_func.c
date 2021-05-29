#include "test_mocks.h"

/****************************************************************************************
*Func desc : This function is to print the passed BMS data to console - stubbed
*Param     : BMSDataArray - Float array pointer which holds the BMS data
			 arraySize    - Size of array passed
			 SenderPrintFormat - Format in which passed data is to be printed
*Return    : None
*****************************************************************************************/
void printToConsole(float * BMSDataArray , int arraySize, enum PRINTFORMAT SenderPrintFormat)
{
	/*realised for only csv format of 2 inputs, code generalisation not realised as it mock*/

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
    /*This condition can be replaced by user stop command too, realised for test purpose */
	if (TestPrintCount[TEMPERATURE] >= MAX_PRINT[TEMPERATURE]) 
	{
		TestInputValue[TEMPERATURE]  = EOF;
	}
	else
	{
	    TestInputValue[TEMPERATURE]  = RandomFloatGeneratorWithinRange(TEMP_MIN, TEMP_MAX);
	}
	
   
    return TestInputValue[TEMPERATURE] ;
}

/****************************************************************************************
*Func desc : This function is to fetch the BMS charge rate value (can be from file or database) - Faked
*Param     : None
*Return    : Returns Temperature value - Float type
*****************************************************************************************/

/*Though it is similar to getBMSTemperatue(), realised seperately to make parameter sources independent*/

float getBMSChargeRate()
{

    if (TestPrintCount[CHARGERATE] >= MAX_PRINT[CHARGERATE])
	{
		TestInputValue[CHARGERATE] = EOF;
	}
	else
	{
	    TestInputValue[CHARGERATE]  = RandomFloatGeneratorWithinRange(CHRGRATE_MIN, CHRGRATE_MAX) ;
	}
	
    return TestInputValue[CHARGERATE] ;
}