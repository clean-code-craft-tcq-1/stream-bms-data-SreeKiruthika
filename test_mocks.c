#include "test_mocks.h"
#include <stdarg.h>

float WriteFormatted ( const char * format, ... )
{
  va_list args;
  float retval;
  va_start (args, format);
  vprintf (format, args);
  retval = va_arg(args, double);
  va_end (args);
  return retval;
}

void mock_console(float temp)
{

float tempOutputTest =	WriteFormatted("%f\n",temp);
	
}


