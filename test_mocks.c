#include "test_mocks.h"

void WriteFormatted ( const char * format, ... )
{
  va_list args;
  float retval;
  va_start (args, format);
  vprintf (format, args);
  tempOutputTest = va_arg(args, double);
  ChrgRateOutputTest = va_arg(args, double);
  va_end (args);

  if((tempInputTest == EOF) || (ChrgRateInputTest == EOF))
  {
    //  assert((tempOutputTest == EOF ));
     // assert((ChrgRateOutputTest  == EOF ));
  }
  else
  {
  assert((tempOutputTest - tempInputTest) <0.01);
  assert((ChrgRateOutputTest - ChrgRateInputTest) <0.01);
  }
}

void printToConsole(float temp, float ChrgRate)
{

   WriteFormatted("%0.2f;%0.2f\n",temp,ChrgRate);
	
}


float RandomFloatGeneratorWithinRange(float min, float max)
{
   return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

