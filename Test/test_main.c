/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "test_mocks.h"

#include <signal.h> 
#include <stdbool.h> 
 
float TestInputValue[NUMOFPARAM] = {0,0};
float TestOutputValue[NUMOFPARAM] = {0,0};
int MAX_PRINT[NUMOFPARAM] = {0,0};
int TestPrintCount[NUMOFPARAM] = {0,0};

void ResetPrintCount()
{
    TestPrintCount[TEMPERATURE] = 0;
    TestPrintCount[CHARGERATE] = 0;
}

void TC_AssignMaxPrint(int Temp,int ChargeRate)
{
    MAX_PRINT[TEMPERATURE] = Temp;
	MAX_PRINT[CHARGERATE] = ChargeRate;
	ResetPrintCount(); /*to reset print count between the test cases*/
    BMSDataToConsoleSender();
    TestPrintCount[TEMPERATURE] = Temp;
    TestPrintCount[CHARGERATE] = ChargeRate;
 //   printf("\n%d,%d",TestPrintCount[TEMPERATURE],TestPrintCount[CHARGERATE]); for debugging
     /*validatePrintedOutput() does validations parallely on each printed output*/
}


int main()
{
    /*Print both param 5 entries*/
    TC_AssignMaxPrint(5,5);
   
    /*Print both param 15 entries*/
    TC_AssignMaxPrint(15,15);
   
   /*Print both param NULL entries*/
    TC_AssignMaxPrint(0,0);
       
    /*Different number of param - temp 9 , ChargeRate 3*/
    TC_AssignMaxPrint(9,3);
    
     /*Different number of param - temp 7 , ChargeRate 10*/
    TC_AssignMaxPrint(7,10);
    
    
    /*Different number of Only temp, no ChargeRate enteries*/
    TC_AssignMaxPrint(17,0);
    
     /*Different number of Only  ChargeRate, no temp enteries*/
    TC_AssignMaxPrint(0,6);
    
    return 0;
}

