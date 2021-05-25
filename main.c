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
int main()
{
    float tempDatabase[]={54.0,37.5,65.9,58.1,99.50,100.3};
    for(int i=0;i<6;i++)
    {
    tempInputTest = tempDatabase[i];
	bmsDataToConsoleSender();
    assert((tempOutputTest-tempInputTest)<0.01);
    }
    return 0;
}
