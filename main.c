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
    tempInputTest = 1.23;
	bmsDataToConsoleSender();
    assert((tempOutputTest-tempInputTest)<0.01);
    return 0;
}
