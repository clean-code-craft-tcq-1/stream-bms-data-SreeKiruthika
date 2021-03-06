#include "test_mocks.h"
#include <math.h>

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
  va_end (args);
	
  va_start (args, format);
  TestOutputValue[TEMPERATURE] = va_arg(args, double);
  TestOutputValue[CHARGERATE]  = va_arg(args, double);
  va_end (args);
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
			assert((int)TestOutputValue[i]  == EOF);
		}
		else
		{
			assert(fabs(TestOutputValue[i] - TestInputValue[i]) < 0.01);
			TestPrintCount[i]++;
		}
	}
}
