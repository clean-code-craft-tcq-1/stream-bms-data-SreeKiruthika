/************************************************************************************************************************/
/* This file contains the inclusions and definitions needed for test functions or mocks*/
/************************************************************************************************************************/

/******************** INCLUDE SECTION ***********************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <math.h>
#include "bms.h"
/************************************************************/



/***************DEFINES section *****************************/


/**************************************************************/



/***************GLOBAL variables section **********************/
extern float TestInputValue[NUMOFPARAM];
extern float TestOutputValue[NUMOFPARAM];
extern int MAX_PRINT[NUMOFPARAM];
extern int TestPrintCount[NUMOFPARAM];
extern int maxCount;
/**************************************************************/

/**************Function prototype section**********************/

void WriteFormatted ( const char * format, ... );

void validatePrintedOutput();
/**************************************************************/


