/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#include "test_mocks.h"
#include "bms.h"

float tempInputTest = 0;
float tempOutputTest = 0;
float ChrgRateInputTest = 0;
float ChrgRateOutputTest = 0;
int MAX_PRINT = 15;

void TC_Print_5()
{
    MAX_PRINT = 5;
    bmsDataToConsoleSender();
}

void TC_Print_15()
{
    MAX_PRINT = 15;
    bmsDataToConsoleSender();
}

void TC_Print_0()
{
    MAX_PRINT = 0;
    bmsDataToConsoleSender();
}

int main()
{
    TC_Print_5();
    TC_Print_15();
    TC_Print_0(); /*Null array*/
    return 0;
}

