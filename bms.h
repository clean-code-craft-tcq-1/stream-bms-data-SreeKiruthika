#include <stdio.h>
#include "test_mocks.h"

enum BATTERYPARAM {TEMPERATURE, CHARGERATE, NUMOFPARAM};

struct BatteryParam_s
{
    char ParamName[20];
    float minValue;
    float maxValue;
};

typedef float (*getParamValue_funcPtr)();
void BMSDataToConsoleSender();
float getBMSTemperatue();
float getBMSChargeRate();
void printToConsole(float * BMSDataArray , int arraySize);
