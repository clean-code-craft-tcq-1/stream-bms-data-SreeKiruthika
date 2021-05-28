#include "bms.h"


struct BatteryParam_s BatteryParam[NUMOFPARAM] = {{"Temperature", TEMP_MIN , TEMP_MAX},
                                                  {"ChargeRate", CHRGRATE_MIN , CHRGRATE_MIN}};

getParamValue_funcPtr getParamValue[NUMOFPARAM] = {getBMSTemperatue , getBMSChargeRate};


void BMSDataToConsoleSender()
{
	float BMSParamValue[NUMOFPARAM];
    int EoFDetected = 0 ; 
	char seperator;
	
	for (int i=0; i < NUMOFPARAM; i++)
	{
	    printf("%s",BatteryParam[i].ParamName);
	    seperator = (i == (NUMOFPARAM-1)) ? '\n':';';
	    printf("%c",seperator);
	}
 
	do
	{
	    for (int i=0 ; i < NUMOFPARAM; i++)
	    {
	        BMSParamValue[i]= getParamValue[i]();
	        if (BMSParamValue[i] == EOF)
	        {
	            EoFDetected = 1;
	        }
	    }
		
	    printToConsole(BMSParamValue,NUMOFPARAM);
	    
	}while(EoFDetected == 0);

}

