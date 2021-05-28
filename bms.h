#include <stdio.h>
#include "test_mocks.h"

#define CHRGRATE_MIN 0.0
#define CHRGRATE_MAX 2.0
#define TEMP_MIN     20.0
#define TEMP_MAX     80.0


void bmsDataToConsoleSender();
float getBMSTemperatue();
float getBMSChrgRate();