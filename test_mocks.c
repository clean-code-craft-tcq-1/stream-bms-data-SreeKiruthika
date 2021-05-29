#include "test_mocks.h"

/****************************************************************************************
*Func desc : This function is to print the BMS data to console and to store the printed data for test purpose - stub
*Param     : Printing data - variable number of arguments
*Return    : None
*****************************************************************************************/
void WriteFormatted ( const char * format, ... )
{
  va_list args;
 
  va_start (args, format);
  vprintf (format, args);
  TestOutputValue[TEMPERATURE] = va_arg(args, double);
  TestOutputValue[CHARGERATE]  = va_arg(args, double);
  va_end (args);
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



/****************************************************************************************
*Func desc : This is test function to validate the each printed output value against the database input value 
			 Each paramater input and output value is verified for each printing
			 To be called after printing is done using mocked "WriteFormatted" where the printed values are updated to output value
*Param     : None
*Return    : None
*****************************************************************************************/
void validatePrintedOutput()
{
	for (int i=0 ; i < NUMOFPARAM ; i++)
	{
		if (TestInputValue[i] == EOF ) 
		{
			assert((int)TestOutputValue[i]  == 0);
		}
		else
		{
			assert((TestOutputValue[i] - TestInputValue[i]) <0.01);
			TestPrintCount[i]++;
		}
	}
}
