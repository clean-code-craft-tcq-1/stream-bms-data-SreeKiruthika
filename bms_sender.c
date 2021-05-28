#include "bms.h"


void bmsDataToConsoleSender()
{
	float tempReceived, tempValidated;
	float ChrgRateReceived, ChrgRateValidated ;
    printf("Temperature;Chargerate\n");
    
	do
	{
		tempReceived = getBMSTemperatue();
     	ChrgRateReceived = getBMSChrgRate();
	    printToConsole(tempReceived,ChrgRateReceived);
	    
	}while((tempReceived != EOF)&&(ChrgRateReceived != EOF));

}

float getBMSTemperatue()
{
	static int i=0;
	if (i >= MAX_PRINT)
	{
		tempInputTest = EOF;
	}
	else
	{
	  tempInputTest = RandomFloatGeneratorWithinRange(TEMP_MIN, TEMP_MAX);
	}
	
	i++;
   
    return tempInputTest;
}

float getBMSChrgRate()
{
	static int i=0;
   
    if (i >= MAX_PRINT)
	{
		ChrgRateInputTest = EOF;
	}
	else
	{
	     ChrgRateInputTest = RandomFloatGeneratorWithinRange(CHRGRATE_MIN, CHRGRATE_MAX) ;
	}
	
	i++;
	
    return ChrgRateInputTest;
}