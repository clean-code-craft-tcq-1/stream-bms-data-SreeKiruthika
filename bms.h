/************************************************************************************************************************/
/* This file contains the inclusions and definitions needed for BMS functions*/
/************************************************************************************************************************/

/******************** INCLUDE SECTION ***********************/
#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "test_mocks.h"
/************************************************************/


/***************DEFINES section *****************************/

#define SENDER_DELAY_SEC 0

/**************************************************************/


/***************GLOBAL variables section **********************/
enum BATTERYPARAM {TEMPERATURE, CHARGERATE, NUMOFPARAM};

enum PRINTFORMAT {CSV};

extern enum PRINTFORMAT SenderPrintFormat ;

struct BatteryParam_s
{
    char ParamName[20];
    float minValue;
    float maxValue;
};

/************************************************************/

/**************Function prototype section**********************/
typedef float (*getParamValue_funcPtr)(); /*Function pointer for all BMS data get functions*/

void BMSDataToConsoleSender(); /*BMS sender function*/

float getBMSTemperatue();  /*Function to get BMS temperature database value - Fake */

float getBMSChargeRate();  /*Function to get BMS charge rate database value - Fake */

void printToConsole(float * BMSDataArray , int arraySize, enum PRINTFORMAT SenderPrintFormat); /*Function to print the data to console - Mocked */
/************************************************************/