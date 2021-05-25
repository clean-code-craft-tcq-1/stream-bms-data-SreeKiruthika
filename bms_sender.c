#include "bms.h"
#include "test_mocks.h"

void bmsDataToConsoleSender ()
{
	float tempReceived, tempValidated;
	float ChrgRateReceived, ChrgRateValidated ;
	tempReceived = getBMSTemperatue();
  //tempValidated = validateTemperature(tempReceived);
//	ChrgRateReceived = getBMSChrgRate();
	//ChrgRateValidated = validateChrgRate (ChrgRateReceived);
	mock_console(tempReceived);
	
}
float getBMSTemperatue()
{
    float retval = tempInputTest;
    return retval;
}