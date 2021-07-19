/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <signal.h> 
#include <stdbool.h> 

#include "bms.h"

bool sig_caught= false; 

int maxCount = 0;
 
void signal_handler(int sig) 
{ 
  if (sig == SIGINT)
  { 
    sig_caught=true; 
  } 
} 
 
int main(int argc,char* argv[])
{
    if (signal(SIGINT, signal_handler) == SIG_ERR) 
    { 
    fprintf(stderr, "signal func registration failed\n"); 
    return 1; 
    }
    if(argc == 2)
    {
        
            maxCount = strtol(argv[1], NULL, 10);
    }
    BMSDataToConsoleSender();
    
    return 0;
}

