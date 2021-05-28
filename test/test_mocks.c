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
  TemperatureOutputTest = va_arg(args, double);
  ChargeRateOutputTest = va_arg(args, double);
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
			 To be called after printing is done using mocked "WriteFormatted" where the printed values are updated to output value
*Param     : None
*Return    : None
*****************************************************************************************/
void validatePrintedOutput()
{
  if((TemperatureInputTest == EOF) || (ChargeRateInputTest == EOF))
  {
     assert((int)TemperatureOutputTest  == 0);
     assert((int)ChargeRateOutputTest == 0);
  }
  else
  {
     assert((TemperatureOutputTest - TemperatureInputTest) <0.01);
     assert((ChargeRateOutputTest - ChargeRateInputTest) <0.01);
  }
}