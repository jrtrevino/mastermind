#include <stdlib.h>
#include <stdio.h>
#include "initializer.h"
#include "game.h"

void exitGame()
{
   fprintf(stderr,"Unexpected EOF\n");
   exit(EXIT_FAILURE);
}

void checkEOF(int test)
{
   if (test == EOF)
      exitGame();
}

void flushBuffer()
{
   while (getchar() != '\n');
}

int checkGuesses()
{
   int flag, guesses;
   guesses = 0;
   while (guesses <= 0)
   {  
      printf("Enter the number of guesses allowed for the game: ");
      flag = scanf("%d",&guesses);
      checkEOF(flag);
      if (guesses >0)
         break;
      flushBuffer();
      printf("The number of guesses must be a positive integer,");
      printf(" please try again\n");
   }
   flushBuffer();
   return guesses;
}  

int checkPositions()
{
   int flag, positions;
   positions = 0;

   while (positions < 1 || positions > 8)
   {
      printf("Enter the number of positions for the game (1-8): ");
      flag = scanf("%d",&positions);
      checkEOF(flag);
      if(positions >0 && positions < 9)
         break;
      flushBuffer();
      printf("The number of positions must be 1-8,");
      printf(" please try again\n");
   }

   flushBuffer();  
   return positions;
}

int checkSeed()
{
   int input,flag;
   printf("Enter the seed for random number generation: ");
   while ((flag = scanf("%d", &input)) != 1)
   {
      checkEOF(flag);
      flushBuffer();
      printf("Seed must be an integer value, please try again\n");
      printf("Enter the seed for random number generation: ");
   }

   flushBuffer(); 
   return input;
}

char checkLetter()
{
   int flag;
   char maxLetter;
   printf("Enter the maximum letter for the game (A-Z): ");
   
   while ((flag = scanf(" %1[A-Z]", &maxLetter)) != 1)
   {
      checkEOF(flag);
      flushBuffer();
      printf("The letter must be an uppercase A-Z, please try again\n");
      printf("Enter the maximum letter for the game (A-Z): ");
   }
 
   flushBuffer();
   return maxLetter;
}

void userInput(int show)
{
   /** gather user input at beginning of game to config game **/
   int guesses,seed, positions;
   char maxLetter;
   char answer[9];
   UserInput currgame;

   seed = checkSeed();
   maxLetter = checkLetter(); 
   positions = checkPositions();
   guesses = checkGuesses();
  
   currgame = makeInput(seed,positions,guesses, maxLetter);
   generateAnswer(&currgame, answer);
   if (show ==0)
      printf("Initialized Game Board: %s\n", answer);
   printf("\n");
   playGame(answer,&currgame);
}
