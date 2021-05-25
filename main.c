/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <assert.h>
#include "test_mocks.h"
#include "bms.h"

float tempInputTest = 0;
float tempOutputTest = 0;
float ChrgRateInputTest = 0;
float ChrgRateOutputTest = 0;
int main()
{
    float tempDatabase[]={54.0,37.5,65.9,58.1,99.50,100.3};
    float ChrgRateDatabase[]={1.5,1.6,1.9,1.2,1.66,1.8};
    for(int i=0;i<6;i++)
    {
    tempInputTest = tempDatabase[i];
    ChrgRateInputTest = ChrgRateDatabase[i];
	bmsDataToConsoleSender();
    assert((tempOutputTest-tempInputTest)<0.01);
    assert((ChrgRateOutputTest-ChrgRateInputTest)<0.01);
    }
    return 0;
}