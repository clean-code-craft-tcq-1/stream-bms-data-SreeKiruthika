#include "bms.h"
#include "test_mocks.h"

void bmsDataToConsoleSender()
{
	float tempReceived;
	float ChrgRateReceived, ChrgRateValidated ;
	tempReceived = getBMSTemperatue();
 	ChrgRateReceived = getBMSChrgRate();
	printToConsole(tempReceived,ChrgRateReceived);
	
}
float getBMSTemperatue()
{
    float retval = tempInputTest;
    return retval;
}

float getBMSChrgRate()
{
    float retval = ChrgRateInputTest;
    return retval;
}