#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ui.h"

void exitFunction()
{
   fprintf(stderr, "Usage: mastermind [-show]\n");
   exit(EXIT_FAILURE);

}

void checkArg(int numArgs , char* argVals[])
{
   char validInput[7] = "-show";
   int equal = strcmp(validInput, argVals[1]);

   /** check to see if user put appropriate command line arg **/
   if (numArgs > 2 || equal != 0)
   {
      exitFunction();
   }
   userInput(equal); 
}

int main(int numArgs, char* argVals[])
{
   if (numArgs != 1)
   {
      checkArg(numArgs, argVals);
   }
   else
   {
      userInput(1);
   }

   return 0;
}
