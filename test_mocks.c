#include "test_mocks.h"
#include <stdarg.h>

void WriteFormatted ( const char * format, ... )
{
  va_list args;
  float retval;
  va_start (args, format);
  vprintf (format, args);
  tempOutputTest = va_arg(args, double);
  ChrgRateOutputTest = va_arg(args, double);
  va_end (args);
 
}

void printToConsole(float temp, float ChrgRate)
{

   WriteFormatted("%.2f;%.2f\n",temp,ChrgRate);
	
}


