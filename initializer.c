#include "initializer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

UserInput makeInput(int s, int mP, int nG, char mL)
{
   UserInput currGame;

   currGame.seed = s;
   currGame.maxPositions = mP;
   currGame.numGuesses = nG;
   currGame.maxLetter = mL;
   return currGame;
}

void generateAnswer(UserInput *config, char answer[])
{
   int i, random, userLetter;

   srand(config->seed);
   userLetter = (config->maxLetter) - 64;
   for (i = 0; i < (config->maxPositions); i++)
   {
      random = rand() % userLetter; 
      answer[i] = 65 + random;
   }

}
