#include "bms.h"
#include <stdbool.h>
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

  printf("%0.2f;%0.2f\n", BMSDataArray[0], BMSDataArray[1]);

}

/****************************************************************************************
*Func desc : This function is to fetch the BMS temperature value (can be from file or database) - Faked
*Param     : None
*Return    : Returns Temperature value - Float type
*****************************************************************************************/

float getBMSTemperatue()
{
    float retval; 
	if(sig_caught == true)
	{
		retval  = EOF;
	}
	else
	{
	    retval  = RandomFloatGeneratorWithinRange(TEMP_MIN, TEMP_MAX);
	}

    return retval ;
}

/****************************************************************************************
*Func desc : This function is to fetch the BMS charge rate value (can be from file or database) - Faked
*Param     : None
*Return    : Returns Temperature value - Float type
*****************************************************************************************/

/*Though it is similar to getBMSTemperatue(), realised seperately to make parameter sources independent*/

float getBMSChargeRate()
{

    float retval;
  
    if(sig_caught == true)
	{
		retval = EOF;
	}
	else
	{
	    retval  = RandomFloatGeneratorWithinRange(CHRGRATE_MIN, CHRGRATE_MAX) ;
	}
	
    return retval ;
}

/****************************************************************************************
*Func desc : This function to generate a random float number within the limits passed
*Param     : min - the minimum value limitation for generated  random number - float type      
			 max - the maximum value limitation for generated  random number - float type 
*Return    : Returns the status of value breach - enum BreachType
*****************************************************************************************/
float RandomFloatGeneratorWithinRange(float min, float max)
{
   return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}
