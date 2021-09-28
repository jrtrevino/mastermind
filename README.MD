# Mastermind
Mastermind is a simple guessing game where the user guesses the correct string of letters based on configuration info.

The user puts in a seed to generate letters, a maximum letter, number of positions, and guess count.

If the user doesn't guess the string in the right amount of guesses, the game is over.

Mastermind supports the `-show` flag to print the answer to the console before the game starts.

## running
To compile the game, type:
```
 $ gcc –Wall game.c initializer.c ui.c mastermind.c -o mastermind
```

After compiling, run the game by typing:
```
./mastermind
```
