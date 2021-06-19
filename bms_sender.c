#include "bms.h"
#include "unistd.h"

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
	int count = 0;
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
	    count++;
	    for (int i=0 ; i < NUMOFPARAM; i++)
	    {
	        BMSParamValue[i]= getParamValue[i]();
	        
	        if (BMSParamValue[i] == EOF || (maxCount > 0 && count == maxCount)) //to provide facility to print only required number of lines
	        {
	            EoFDetected ++ ;
	        }
	    }
		
	    printToConsole(BMSParamValue, NUMOFPARAM , SenderPrintFormat);
	
	    sleep(SENDER_DELAY_SEC);
	    
	}while(!(EoFDetected == NUMOFPARAM));
	if(maxCount > 0){
		printf("-1.00;-1.00"); //to keep last result same as EOF using ctrl+C
	}
}

