#include "initializer.h"
#include "ui.h"
#include "game.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int checkExact(char input[], char answer[])
{
   int len, counter, exact;
   len = strlen(answer);
   exact = 0;

   for (counter = 0; counter < len; counter++)
   {
      if (input[counter] == answer[counter])
         exact++;
   }
   return exact;

}
void answerOut(int numExact,int length, int guessCount, int inexact)
{
  
   if (numExact == length && guessCount == 1)
   {
      printf("\nWow, you won in 1 guesses - well done!\n");
      exit(0);
   }
   else if (numExact == length)
   { 
      printf("\nWow, you won in %d guesses - well done!\n", guessCount);
      exit(0);
   }
   else
   {
      printf("Nope, %d exact guesses and %d inexact guesses\n\n",
         numExact, inexact);
   }
}

int arrayCycle(int dupl, char userAnswer,char answerCopy[])
{
   int j, length, occurences;
   occurences = 0;
   length = strlen(answerCopy);

   for (j = 0; j < length; j++)
   {
      if ((userAnswer == answerCopy[j]) && (dupl != 1))
      {   
         answerCopy[j] = '0';
         occurences++;
         dupl = 1;
      }
   }
   return occurences;
}

int finalCheck(int test, char userAnswer[], char realAnswer[], int guessCount)
{
   int i,exact, length,occurences, inexact;
   char answerCopy[9];
   occurences = 0;
   length = strlen(realAnswer);
   memcpy(answerCopy,realAnswer,9);
   exact = checkExact(userAnswer,realAnswer);
   for (i = 0; i < length ; i++)
   {
      occurences += arrayCycle(0, userAnswer[i], answerCopy);
   }
   
   inexact = occurences - exact;
   answerOut(exact,length,guessCount, inexact);
   return test;
}

int checkChar(char c, int maxValidChar)
{
   if((isupper(c) == 0 || c < 65) || c > maxValidChar)
   {
      return 1;
   }

   return 0;
}

int checkValidInput(UserInput *game, char answer[], int guessCount)
{
   int i,invalid, counter;
   int curr;
   char user[9];
   int maxValidChar;
   invalid = 0;
   counter = 0;
   i = 0;
   maxValidChar = game->maxLetter;
   while((counter < game->maxPositions))
   {
      curr = getchar();
      checkEOF(curr);
      if (curr != '\n' && isspace(curr) == 0)
      {
         invalid += checkChar(curr, maxValidChar);
         user[counter] = curr;
         counter++;
      }
   }
   flushBuffer();
   if (invalid != 0)
      return 1;

   i=finalCheck(0,user,answer, guessCount);
   return i;  
}

void playGame(char answer[], UserInput *game)
{
   
   int i;
   int guessLimit;
   i = 1;
   guessLimit = game->numGuesses;
   while(i <= guessLimit)
   {
      printf("Enter guess %d: ", i);
      if(checkValidInput(game,answer,i) == 1)
      {
         printf("Invalid guess, please try again\n\n");
         i--;
      }
      i++;
   }

   printf("Game over, you ran out of guesses. Better luck next time!\n");
}
