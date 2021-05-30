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
 
void signal_handler(int sig) 
{ 
  if (sig == SIGINT)
  { 
    sig_caught=true; 
  } 
} 
 
int main()
{
    if (signal(SIGINT, signal_handler) == SIG_ERR) 
    { 
    fprintf(stderr, "signal func registration failed\n"); 
    return 1; 
    }
    
    BMSDataToConsoleSender();
    
    return 0;
}

