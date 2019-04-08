#ifndef TESTINGPOINTS_H_INCLUDED
#define TESTINGPOINTS_H_INCLUDED

int asciiCode ( char x );
void testPointsChar (char x1[3], char y1[3], char z1[3], char l1[3], int *x, int *y, int *z, int *l, int *testFlag, int *flagTest);
void undoRedoSaveExitCheck (play playMatrix[11][11], char player1[], char player2[], char player[], int order, int f, int t, int *flagTest, int *flag9, int x, int y, int z, int l, int numberLines, int lineCounter, int undoScoreFlag, int undoFlag, int vs, int th, int tm,int ts,int move1, int move2,int turn, int totalScore);

#endif // TESTINGPOINTS_H_INCLUDED
