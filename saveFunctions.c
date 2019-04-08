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



void saveFunction1 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int undoFlag, int undoScoreFlag){

    int i,j,fg;

    fg=0;

    FILE *fp;

    if (flag==1){
        fp = fopen("save (1).txt","w");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","w");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","w");
    }

    else {fp = fopen("save.txt","w");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fprintf(fp,"%d \n",f);
    fprintf(fp,"%d \n",vs);

/* **********************************Names************************************************** */

    fprintf(fp,"%s \n",player1);
    fprintf(fp,"%s \n",player2);
    fprintf(fp,"%s \n",player);


/* **********************************LINES************************************************* */
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%d ",playMatrix[i][j].line);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%s ",playMatrix[i][j].box);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%s ",playMatrix[i][j].name);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%d ",playMatrix[i][j].order);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

       fprintf(fp,"%d \n",order);


    /* ****************************** Time ************************************ */

        fprintf(fp,"%d : %d : %d \n",th,tm,ts);
        fprintf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fprintf(fp,"%d  \n",move1);
        fprintf(fp,"\n");

        fprintf(fp,"%d  \n",move2);
        fprintf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fprintf(fp,"%d \n",numberLines);
         fprintf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fprintf(fp,"%d \n",turn);
        fprintf(fp,"\n");

        fprintf(fp,"%d \n",totalScore);

        fprintf(fp,"%d \n",undoFlag);

        fprintf(fp,"%d \n",undoScoreFlag);


    }

    fclose(fp);
}

void saveFunction2 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int undoFlag, int undoScoreFlag){

    int i,j,fg;

    fg=0;

    FILE *fp;

    if (flag==1){
        fp = fopen("save (1).txt","w");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","w");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","w");
    }

    else {fp = fopen("save.txt","w");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fprintf(fp,"%d \n",f);
    fprintf(fp,"%d \n",vs);

/* **********************************Names************************************************** */

    fprintf(fp,"%s \n",player1);
    fprintf(fp,"%s \n",player2);
    fprintf(fp,"%s \n",player);


/* **********************************LINES************************************************* */
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%d ",playMatrix[i][j].line);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%s ",playMatrix[i][j].box);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%s ",playMatrix[i][j].name);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%d ",playMatrix[i][j].order);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

       fprintf(fp,"%d \n",order);


    /* ****************************** Time ************************************ */

        fprintf(fp,"%d : %d : %d \n",th,tm,ts);
        fprintf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fprintf(fp,"%d  \n",move1);
        fprintf(fp,"\n");

        fprintf(fp,"%d  \n",move2);
        fprintf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fprintf(fp,"%d \n",numberLines);
         fprintf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fprintf(fp,"%d \n",turn);
        fprintf(fp,"\n");

        fprintf(fp,"%d \n",totalScore);

        fprintf(fp,"%d \n",undoFlag);

        fprintf(fp,"%d \n",undoScoreFlag);


    }

    fclose(fp);
}

void saveFunctionComputer1 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int orderClear, int undoFlag){

    int i,j,fg;

    fg=0;

    FILE *fp;

    if (flag==1){
        fp = fopen("save (1).txt","w");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","w");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","w");
    }

    else {fp = fopen("save.txt","w");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fprintf(fp,"%d \n",f);
    fprintf(fp,"%d \n",vs);

/* **********************************Names************************************************** */

    fprintf(fp,"%s \n",player1);
    fprintf(fp,"%s \n",player2);
    fprintf(fp,"%s \n",player);


/* **********************************LINES************************************************* */
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%d ",playMatrix[i][j].line);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%s ",playMatrix[i][j].box);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%s ",playMatrix[i][j].name);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<11;i++){
         for(j=0;j<11;j++){
            fprintf(fp,"%d ",playMatrix[i][j].order);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

       fprintf(fp,"%d \n",order);


    /* ****************************** Time ************************************ */

        fprintf(fp,"%d : %d : %d \n",th,tm,ts);
        fprintf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fprintf(fp,"%d  \n",move1);
        fprintf(fp,"\n");

        fprintf(fp,"%d  \n",move2);
        fprintf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fprintf(fp,"%d \n",numberLines);
         fprintf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fprintf(fp,"%d \n",turn);
        fprintf(fp,"\n");

        fprintf(fp,"%d \n",totalScore);

        fprintf(fp,"%d \n",undoFlag);

        fprintf(fp,"%d \n",orderClear);


    }

    fclose(fp);
}

void saveFunctionComputer2 (int f, int vs, play playMatrix[][11], char player1[], char player2[], char player[], int th, int tm , int ts, int move1, int move2, int numberLines , int turn, int totalScore, int flag, int order, int orderClear, int undoFlag){

    int i,j,fg;

    fg=0;

    FILE *fp;

    if (flag==1){
        fp = fopen("save (1).txt","w");
    }
    else if (flag==2){
        fp = fopen("save (2).txt","w");
    }
    else if (flag==3){
        fp = fopen("save (3).txt","w");
    }

    else {fp = fopen("save.txt","w");}

    if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }

    else{

/* **********************************MODE************************************************** */

    fprintf(fp,"%d \n",f);
    fprintf(fp,"%d \n",vs);

/* **********************************Names************************************************** */

    fprintf(fp,"%s \n",player1);
    fprintf(fp,"%s \n",player2);
    fprintf(fp,"%s \n",player);


/* **********************************LINES************************************************* */
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%d ",playMatrix[i][j].line);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* ************************************BOXES*******************************************************/
       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%s ",playMatrix[i][j].box);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");
/* ***********************************NAME********************************************************/

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%s ",playMatrix[i][j].name);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

/* *************************************ORDER******************************************************* */

       for(i=0;i<5;i++){
         for(j=0;j<5;j++){
            fprintf(fp,"%d ",playMatrix[i][j].order);
         }
         fprintf(fp,"\n");
       }
       fprintf(fp,"\n");

       fprintf(fp,"%d \n",order);


    /* ****************************** Time ************************************ */

        fprintf(fp,"%d : %d : %d \n",th,tm,ts);
        fprintf(fp,"\n");


    /* ****************************** No.Of Moves ***************************** */
        fprintf(fp,"%d  \n",move1);
        fprintf(fp,"\n");

        fprintf(fp,"%d  \n",move2);
        fprintf(fp,"\n");

    /* ***************************** No.Of Lines Left ************************* */
         fprintf(fp,"%d \n",numberLines);
         fprintf(fp,"\n");

    /* ***************************** Turn ************************************* */

        fprintf(fp,"%d \n",turn);
        fprintf(fp,"\n");

        fprintf(fp,"%d \n",totalScore);

        fprintf(fp,"%d \n",undoFlag);

        fprintf(fp,"%d \n",orderClear);


    }

    fclose(fp);
}

void saveHighscore(highScoreStruct highScore[10]){

    int i;

    FILE *fp;

    fp=fopen("HighScore.txt","w");

    if (fp == NULL) {
        printf("I couldn't open results.dat for writing.\n");
        exit(0);
    }

    else {
        for (i=0;i<10;i++){
            fprintf(fp,"%s",highScore[i].playerName);
            fprintf(fp," %d\n\n",highScore[i].score);
        }
    }

    fclose(fp);

}
