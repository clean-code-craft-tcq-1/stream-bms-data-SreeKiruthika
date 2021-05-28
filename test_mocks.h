#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <math.h>

#define CHRGRATE_MIN 0.0
#define CHRGRATE_MAX 2.0
#define TEMP_MIN     20.0
#define TEMP_MAX     80.0

float RandomFloatGeneratorWithinRange(float min, float max);
void WriteFormatted ( const char * format, ... );
void validatePrintedOutput();


extern float TemperatureInputTest;
extern float TemperatureOutputTest;
extern float ChargeRateInputTest;
extern float ChargeRateOutputTest;
extern int MAX_PRINT;
