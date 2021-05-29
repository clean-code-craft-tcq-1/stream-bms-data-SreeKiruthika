#include "bms.h"

/* Structure initialisation of battery parameters */
struct BatteryParam_s BatteryParam[NUMOFPARAM] = {{"Temperature", TEMP_MIN , TEMP_MAX},
                                                  {"ChargeRate", CHRGRATE_MIN , CHRGRATE_MIN}};

/* Function pointer initialisation with functions to get battery parameters */
getParamValue_funcPtr getParamValue[NUMOFPARAM] = {getBMSTemperatue , getBMSChargeRate};

/*Initialising print format , can be realised in scanf to*/
enum PRINTFORMAT SenderPrintFormat  = CSV;

/****************************************************************************************
*Func desc : This function is to collect BMS data and print to console 
*Param     : None
*Return    : None
*****************************************************************************************/
void BMSDataToConsoleSender()
{
	float BMSParamValue[NUMOFPARAM];
    int EoFDetected = 0 ; 
	char seperator;
	
	if( SenderPrintFormat == CSV) /*Needed only for CSV format as the param names are typed before data
									In other formats it is typed along with data say JSON*/
	{
	   for (int i=0; i < NUMOFPARAM; i++)
	   {
	     printf("%s",BatteryParam[i].ParamName);
	     seperator = (i == (NUMOFPARAM-1)) ? '\n':';';
	     printf("%c",seperator);
	    }
	}	
 
	do
	{
	    EoFDetected = 0;
	    
	    for (int i=0 ; i < NUMOFPARAM; i++)
	    {
	        BMSParamValue[i]= getParamValue[i]();
	        
	        if (BMSParamValue[i] == EOF)
	        {
	            EoFDetected ++ ;
	        }
	    }
		
	    printToConsole(BMSParamValue, NUMOFPARAM , SenderPrintFormat);
	
	    sleep(SENDER_DELAY_SEC);
	    
	}while(!(EoFDetected == NUMOFPARAM));

}

