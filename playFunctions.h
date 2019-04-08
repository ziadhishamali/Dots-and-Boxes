#ifndef PLAYFUNCTIONS_H_INCLUDED
#define PLAYFUNCTIONS_H_INCLUDED

typedef struct{

        int line;
        char name[16];
        char box[16];
        int order;

    }play;

typedef struct {

    int score;
    char playerName[16];

}highScoreStruct;
int testPoints (char x, char y, char z, char l);
int asciiCode ( char x );
void testPointsChar (char x1[2], char y1[2], char z1[2], char l1[2], int *x, int *y, int *z, int *l, int *testFlag, int *flagTest);
int ai_2Lines (play playMatrix[11][11], int f, int t);
void ai_2Lines_counter (play playMatrix[11][11], int *flag, int i, int j);
void ai_2Lines_test (play playMatrix[11][11], int x, int y, int z, int l, int *flagTest);
void playFunctionComputer (char gameDifficulty[], char mainMenu[], int loadFlag, int modeFlag);
void playFunction (char gameDifficulty[], char mainMenu[], int loadFlag, int modeFlag);
#endif // PLAYFUNCTIONS_H_INCLUDED


