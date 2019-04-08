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

void undoFunctionComputer (play playMatrix[][11], int f, int t, int *order, int *move1, int *move2, int *turn, int *numberLines, char player1[], char player2[]){

    int i,j,flag=0,orderFlag=0,flag2=0;
    char edit[16]="000000000000000";

    for (i=0;i<f;i++){
        if (flag2==1){
            break;
        }
        for (j=0;j<t;j++){
            if (playMatrix[i][j].order==*order && !strcmp(playMatrix[i][j].name,player2)){

                playMatrix[i][j].line=0;

                *move2=*move2-1;
                *numberLines=*numberLines+1;

                if (playMatrix[i+1][j].line==6){

                    if (!(strcmp(playMatrix[i+1][j].box,player1)) || !(strcmp(playMatrix[i+1][j].box,player2))){
                        strcpy(playMatrix[i+1][j].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i-1][j].line==6){

                    if (!(strcmp(playMatrix[i-1][j].box,player1)) || !(strcmp(playMatrix[i-1][j].box,player2))){
                        strcpy(playMatrix[i-1][j].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i][j+1].line==6){

                    if (!(strcmp(playMatrix[i][j+1].box,player1)) || !(strcmp(playMatrix[i][j+1].box,player2))){
                        strcpy(playMatrix[i][j+1].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i][j-1].line==6){
                    if (!(strcmp(playMatrix[i][j-1].box,player1)) || !(strcmp(playMatrix[i][j-1].box,player2))){
                        strcpy(playMatrix[i][j-1].box,edit);
                        flag=1;
                    }
                }

                *order=*order-1;
                for (i=0;i<f;i++){
                    for (j=0;j<t;j++){
                        if (playMatrix[i][j].order==*order){
                            if (!strcmp(playMatrix[i][j].name,player1)){
                                orderFlag=1;
                                i=0,j=0;
                                break;
                            }
                            else if (!strcmp(playMatrix[i][j].name,player2)){
                                orderFlag=2;
                                i=0,j=0;
                                break;
                            }
                        }
                    }
                    if (orderFlag==1 || orderFlag==2){
                        break;
                    }
                }
            }


            else if (playMatrix[i][j].order==*order && !strcmp(playMatrix[i][j].name,player1)){

                playMatrix[i][j].line=0;

                *move1=*move1-1;
                *numberLines=*numberLines+1;

                if (playMatrix[i+1][j].line==6){

                    if (!(strcmp(playMatrix[i+1][j].box,player1)) || !(strcmp(playMatrix[i+1][j].box,player2))){
                        strcpy(playMatrix[i+1][j].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i-1][j].line==6){

                    if (!(strcmp(playMatrix[i-1][j].box,player1)) || !(strcmp(playMatrix[i-1][j].box,player2))){
                        strcpy(playMatrix[i-1][j].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i][j+1].line==6){

                    if (!(strcmp(playMatrix[i][j+1].box,player1)) || !(strcmp(playMatrix[i][j+1].box,player2))){
                        strcpy(playMatrix[i][j+1].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i][j-1].line==6){
                    if (!(strcmp(playMatrix[i][j-1].box,player1)) || !(strcmp(playMatrix[i][j-1].box,player2))){
                        strcpy(playMatrix[i][j-1].box,edit);
                        flag=1;
                    }
                }
                flag2=1;
                break;
            }
        }
    }
    if (flag==1){
        *turn=*turn+1;
    }
}

int redoFunctionComputer (play playMatrix[][11],int f, int t, int *order, int *move, int *turn, int *numberLines, char player[]){

    int i,j,flag=0;

    for (i=0;i<t;i++){
        for (j=0;j<f;j++){
            if (playMatrix[i][j].order==*order){

                playMatrix[i][j].line=1;

                *move=*move+1;
                *numberLines=*numberLines-1;

                if (playMatrix[i+1][j].line==6){
                    if (playMatrix[i+1+1][j].line==1 && playMatrix[i+1-1][j].line==1 && playMatrix[i+1][j+1].line==1 && playMatrix[i+1][j-1].line==1){
                        strcpy(playMatrix[i+1][j].box,player);
                        flag=1;
                    }
                }
                if (playMatrix[i-1][j].line==6){
                    if (playMatrix[i-1+1][j].line==1 && playMatrix[i-1-1][j].line==1 && playMatrix[i-1][j+1].line==1 && playMatrix[i-1][j-1].line==1){
                        strcpy(playMatrix[i-1][j].box,player);
                        flag=1;
                    }
                }
                if (playMatrix[i][j+1].line==6){
                    if (playMatrix[i+1][j+1].line==1 && playMatrix[i-1][j+1].line==1 && playMatrix[i][j+1+1].line==1 && playMatrix[i][j+1-1].line==1){
                        strcpy(playMatrix[i][j+1].box,player);
                        flag=1;
                    }
                }
                if (playMatrix[i][j-1].line==6){
                    if (playMatrix[i+1][j-1].line==1 && playMatrix[i-1][j-1].line==1 && playMatrix[i][j-1+1].line==1 && playMatrix[i][j-1-1].line==1){
                        strcpy(playMatrix[i][j-1].box,player);
                        flag=1;
                    }
                }
            }
        }
    }
    return flag;

}

int undoFunction (play playMatrix[][11],int f, int t, int order, char player1[], char player2[]){

    int i,j,flag=0,orderFlag=0;
    char edit[16]="000000000000000";

    for (i=0;i<t;i++){
        for (j=0;j<f;j++){
            if (playMatrix[i][j].order==order){

                playMatrix[i][j].line=0;

                if (playMatrix[i+1][j].line==6){

                    if (!(strcmp(playMatrix[i+1][j].box,player1)) || !(strcmp(playMatrix[i+1][j].box,player2))){
                        strcpy(playMatrix[i+1][j].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i-1][j].line==6){

                    if (!(strcmp(playMatrix[i-1][j].box,player1)) || !(strcmp(playMatrix[i-1][j].box,player2))){
                        strcpy(playMatrix[i-1][j].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i][j+1].line==6){

                    if (!(strcmp(playMatrix[i][j+1].box,player1)) || !(strcmp(playMatrix[i][j+1].box,player2))){
                        strcpy(playMatrix[i][j+1].box,edit);
                        flag=1;
                    }
                }
                if (playMatrix[i][j-1].line==6){
                    if (!(strcmp(playMatrix[i][j-1].box,player1)) || !(strcmp(playMatrix[i][j-1].box,player2))){
                        strcpy(playMatrix[i][j-1].box,edit);
                        flag=1;
                    }
                }
            }
        }
    }
    return flag;
}

void redoFunction (play playMatrix[][11],int f, int t, int order, char player[]){

    int i,j;

    for (i=0;i<t;i++){
        for (j=0;j<f;j++){
            if (playMatrix[i][j].order==order){
                playMatrix[i][j].line=1;
                if (playMatrix[i+1][j].line==6){
                    if (playMatrix[i+1+1][j].line==1 && playMatrix[i+1-1][j].line==1 && playMatrix[i+1][j+1].line==1 && playMatrix[i+1][j-1].line==1){
                        strcpy(playMatrix[i+1][j].box,player);
                    }
                }
                if (playMatrix[i-1][j].line==6){
                    if (playMatrix[i-1+1][j].line==1 && playMatrix[i-1-1][j].line==1 && playMatrix[i-1][j+1].line==1 && playMatrix[i-1][j-1].line==1){
                        strcpy(playMatrix[i-1][j].box,player);
                    }
                }
                if (playMatrix[i][j+1].line==6){
                    if (playMatrix[i+1][j+1].line==1 && playMatrix[i-1][j+1].line==1 && playMatrix[i][j+1+1].line==1 && playMatrix[i][j+1-1].line==1){
                        strcpy(playMatrix[i][j+1].box,player);
                    }
                }
                if (playMatrix[i][j-1].line==6){
                    if (playMatrix[i+1][j-1].line==1 && playMatrix[i-1][j-1].line==1 && playMatrix[i][j-1+1].line==1 && playMatrix[i][j-1-1].line==1){
                        strcpy(playMatrix[i][j-1].box,player);
                    }
                }
            }
        }
    }
}
