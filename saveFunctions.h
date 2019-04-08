#ifndef SAVEFUNCTIONS_H_INCLUDED
#define SAVEFUNCTIONS_H_INCLUDED

void saveFunction1 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int undoFlag, int undoScoreFlag);
void saveFunction2 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int undoFlag, int undoScoreFlag);
void saveFunctionComputer1 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int orderClear, int undoFlag);
void saveFunctionComputer2 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int orderClear, int undoFlag);
void saveHighscore(highScoreStruct highScore[10]);

#endif // SAVEFUNCTIONS_H_INCLUDED
