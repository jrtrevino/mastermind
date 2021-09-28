#ifndef INITIALIZER_H
#define INITIALIZER_H

typedef struct
{
  int seed, maxPositions, numGuesses;
  char maxLetter;
  char answer[9];

} UserInput;

UserInput makeInput(int s, int mP, int nG, char mL);

void generateAnswer(UserInput *input, char * answer);

#endif
