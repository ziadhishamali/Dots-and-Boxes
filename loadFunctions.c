#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

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


void loadFunction2 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *undoFlag, int *undoScoreFlag){

    int i,j;


    FILE *fp;


    if (flag==1){
        fp = fopen("save (1).txt","r");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","r");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","r");
    }
    else {fp = fopen("save.txt","r");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fscanf(fp,"%d \n",&f);
    fscanf(fp,"%d \n",&vs);


/* **********************************Names************************************************** */

    fscanf(fp,"%s \n",player1);
    fscanf(fp,"%s \n",player2);
    fscanf(fp,"%s \n",player);

/* **********************************LINES************************************************* */
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].line);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%s ",playMatrix[i][j].box);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%s ",playMatrix[i][j].name);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].order);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

       fscanf(fp,"%d \n",&*order);


    /* ****************************** Time ************************************ */

        fscanf(fp,"%d : %d : %d \n",&*th,&*tm,&*ts);
        fscanf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fscanf(fp,"%d  \n",&*move1);
        fscanf(fp,"\n");

        fscanf(fp,"%d  \n",&*move2);
        fscanf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fscanf(fp,"%d \n",&*numberLines);
         fscanf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fscanf(fp,"%d \n",&*turn);
        fscanf(fp,"\n");

        fscanf(fp,"%d \n",&*totalScore);

        fscanf(fp,"%d \n",&*undoFlag);

        fscanf(fp,"%d \n",&*undoScoreFlag);



    }

    fclose(fp);
}

void loadFunctionComputer2 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *orderClear, int *undoFlag){

    int i,j;


    FILE *fp;


    if (flag==1){
        fp = fopen("save (1).txt","r");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","r");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","r");
    }
    else {fp = fopen("save.txt","r");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fscanf(fp,"%d \n",&f);
    fscanf(fp,"%d \n",&vs);


/* **********************************Names************************************************** */

    fscanf(fp,"%s \n",player1);
    fscanf(fp,"%s \n",player2);
    fscanf(fp,"%s \n",player);

/* **********************************LINES************************************************* */
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].line);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%s ",playMatrix[i][j].box);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%s ",playMatrix[i][j].name);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].order);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

       fscanf(fp,"%d \n",&*order);


    /* ****************************** Time ************************************ */

        fscanf(fp,"%d : %d : %d \n",&*th,&*tm,&*ts);
        fscanf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fscanf(fp,"%d  \n",&*move1);
        fscanf(fp,"\n");

        fscanf(fp,"%d  \n",&*move2);
        fscanf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fscanf(fp,"%d \n",&*numberLines);
         fscanf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fscanf(fp,"%d \n",&*turn);
        fscanf(fp,"\n");

        fscanf(fp,"%d \n",&*totalScore);

        fscanf(fp,"%d \n",&*undoFlag);

        fscanf(fp,"%d \n",&*orderClear);



    }

    fclose(fp);
}

void loadFunction1 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *undoFlag, int *undoScoreFlag){

    int i,j;


    FILE *fp;


    if (flag==1){
        fp = fopen("save (1).txt","r");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","r");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","r");
    }
    else {fp = fopen("save.txt","r");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fscanf(fp,"%d \n",&f);
    fscanf(fp,"%d \n",&vs);


/* **********************************Names************************************************** */

    fscanf(fp,"%s \n",player1);
    fscanf(fp,"%s \n",player2);
    fscanf(fp,"%s \n",player);

/* **********************************LINES************************************************* */
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].line);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%s ",playMatrix[i][j].box);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%s ",playMatrix[i][j].name);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].order);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

       fscanf(fp,"%d ",&*order);


    /* ****************************** Time ************************************ */

        fscanf(fp,"%d : %d : %d \n",&*th,&*tm,&*ts);
        fscanf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fscanf(fp,"%d  \n",&*move1);
        fscanf(fp,"\n");

        fscanf(fp,"%d  \n",&*move2);
        fscanf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fscanf(fp,"%d \n",&*numberLines);
         fscanf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fscanf(fp,"%d \n",&*turn);
        fscanf(fp,"\n");

        fscanf(fp,"%d \n",&*totalScore);

        fscanf(fp,"%d \n",&*undoFlag);

        fscanf(fp,"%d \n",&*undoScoreFlag);


    }

    fclose(fp);
}

void loadFunctionComputer1 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int *th, int *tm ,int *ts,int *move1, int *move2, int *numberLines , int *turn, int *totalScore, int flag, int *order, int *orderClear, int *undoFlag){

    int i,j;


    FILE *fp;


    if (flag==1){
        fp = fopen("save (1).txt","r");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","r");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","r");
    }
    else {fp = fopen("save.txt","r");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fscanf(fp,"%d \n",&f);
    fscanf(fp,"%d \n",&vs);


/* **********************************Names************************************************** */

    fscanf(fp,"%s \n",player1);
    fscanf(fp,"%s \n",player2);
    fscanf(fp,"%s \n",player);

/* **********************************LINES************************************************* */
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].line);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%s ",playMatrix[i][j].box);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%s ",playMatrix[i][j].name);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fscanf(fp,"%d ",&playMatrix[i][j].order);
         }
         fscanf(fp,"\n");
       }
       fscanf(fp,"\n");

       fscanf(fp,"%d ",&*order);


    /* ****************************** Time ************************************ */

        fscanf(fp,"%d : %d : %d \n",&*th,&*tm,&*ts);
        fscanf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fscanf(fp,"%d  \n",&*move1);
        fscanf(fp,"\n");

        fscanf(fp,"%d  \n",&*move2);
        fscanf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fscanf(fp,"%d \n",&*numberLines);
         fscanf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fscanf(fp,"%d \n",&*turn);
        fscanf(fp,"\n");

        fscanf(fp,"%d \n",&*totalScore);

        fscanf(fp,"%d \n",&*undoFlag);

        fscanf(fp,"%d \n",&*orderClear);


    }

    fclose(fp);
}

void loadHighscore(highScoreStruct highScore[10]){

    int i;

    FILE *fp;

    fp=fopen("HighScore.txt","r");

    if (fp == NULL) {
        printf("I couldn't open results.dat for writing.\n");
        exit(0);
    }

    else {
        for (i=0;i<10;i++){
            fscanf(fp,"%s",highScore[i].playerName);
            fscanf(fp," %d\n\n",&highScore[i].score);
        }
    }

    fclose(fp);

}

