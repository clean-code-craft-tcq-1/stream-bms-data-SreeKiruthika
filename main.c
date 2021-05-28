/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#include "test_mocks.h"
#include "bms.h"

float TemperatureInputTest = 0;
float TemperatureOutputTest = 0;
float ChargeRateInputTest = 0;
float ChargeRateOutputTest = 0;
int MAX_PRINT = 0;

void TC_Print5()
{
    MAX_PRINT = 5;
    BMSDataToConsoleSender();
     /*validatePrintedOutput() does validations parallely on each printed output*/
}

void TC_Print15()
{
    MAX_PRINT = 15;
    BMSDataToConsoleSender();
     /*validatePrintedOutput() does validations parallely on each printed output*/
}

void TC_Print0()
{
    MAX_PRINT = 0;
    BMSDataToConsoleSender();
    /*validatePrintedOutput() does validations parallely on each printed output*/
}

int main()
{
    TC_Print5();
    TC_Print15();
    TC_Print0(); /*Null array*/
    return 0;
}

