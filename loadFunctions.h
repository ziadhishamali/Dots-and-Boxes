#ifndef LOADFUNCTIONS_H_INCLUDED
#define LOADFUNCTIONS_H_INCLUDED


typedef struct{

        int line;
        char name[16]; //To store whose player played the line
        char box[16];  //To store whose player completed a box
        int order;   //To store the order by which lines are played for undo and redo purposes

    }play;

typedef struct {

    int score;
    char playerName[16];

}highScoreStruct;

void loadFunction1 (int f, int vs, play playMatrix[11][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *undoFlag, int *undoScoreFlag);
void loadFunction2 (int f, int vs, play playMatrix[11][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *undoFlag, int *undoScoreFlag);
void loadFunctionComputer1 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *orderClear, int *undoFlag);
void loadFunctionComputer2 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *orderClear, int *undoFlag);
void loadHighscore(highScoreStruct highScore[10]);

#endif // LOADFUNCTIONS_H_INCLUDED
