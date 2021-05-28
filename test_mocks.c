#include "test_mocks.h"

void WriteFormatted ( const char * format, ... )
{
  va_list args;
 
  va_start (args, format);
  vprintf (format, args);
  TemperatureOutputTest = va_arg(args, double);
  ChargeRateOutputTest = va_arg(args, double);
  va_end (args);
}

float RandomFloatGeneratorWithinRange(float min, float max)
{
   return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

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