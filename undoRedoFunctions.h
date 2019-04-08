#ifndef UNDOREDOFUNCTIONS_H_INCLUDED
#define UNDOREDOFUNCTIONS_H_INCLUDED

void undoFunctionComputer (play playMatrix[][11], int f, int t, int *order, int *move1, int *move2, int *turn, int *numberLines, char player1[], char player2[]);
int redoFunctionComputer (play playMatrix[][11],int f, int t, int *order, int *move, int *turn, int *numberLines, char player[]);
int undoFunction (play playMatrix[][11],int f, int t, int order, char player1[], char player2[]);
void redoFunction (play playMatrix[][11],int f, int t, int order, char player[]);

#endif // UNDOREDOFUNCTIONS_H_INCLUDED
