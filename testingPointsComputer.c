#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include "playFunctions.h"
#include "saveFunctions.h"
#include "undoRedoFunctions.h"
#include "gettingNames.h"
#include "testingPoints.h"

void undoRedoSaveExitCheckComputer (play playMatrix[11][11], char player1[], char player2[], char player[], int *order, int *orderClear, int *orderCopy, int f, int t, int *flagTest, int *flag9, int x, int y, int z, int l, int *numberLines, int *lineCounter, int *undoFlag, int *undoFlag4, int *redoScoreFlag, int vs, int th, int tm, int ts, int *move1, int *move2, int *turn, int totalScore){

    int flag=0;
    int temp,saveFlag2=0,exitFlag1=0,exitFlag2=0,i=0,saveFlag=0;
    char exitFlag[3];
    char save[3];

    if (x==69 && y==69 && z==69 && l==69){
        if (*numberLines==*lineCounter){
            *flagTest=0;
            *flag9=0;
            flag=1;
        }

        if (flag==0){
            *orderCopy=*order;
            undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
            *orderClear=(*orderCopy)-(*order)+1;
            *flagTest=0;
            *flag9=0;
        }
    }

    else if (x==66 && y==66 && z==66 && l==66){
        if (!undoFlag){
            *flagTest=0;
            *flag9=0;
            flag=1;
        }

        if (flag==0){
            if (undoFlag4==1){
                *order=0;
            }

            *order++;
            *redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
            *orderClear--;
            if (redoScoreFlag==0){
                *order++;
                *redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                *orderClear--;
                while (redoScoreFlag==1){
                    *order++;
                    *redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                    *orderClear--;
                    *turn=1;
                }
            }
            *flagTest=0;
            *flag9=0;
        }

    }
    else if (x==67 && y==67 && z==67 && l==67){
        printf("Select the save file: \n\n");
        printf("(1) Save 1\n");
        printf("(2) Save 2\n");
        printf("(3) Save 3\n");

        while (saveFlag2==0){
            i=0;
            while ((saveFlag=getchar())!='\n'){
                if (i<2){
                    save[i]=saveFlag;
                    i++;
                }
            }
            save[i]='\0';
            if (save[0]=='\0' || save[0]==' ' || save[0]=='\t' || (save[0]!='1' && save[0]!='2' && save[0]!='3') || save[1]!='\0'){
                printf("Choose the Right File!!");
                saveFlag2=0;
                i=0;
            }
            else {
                saveFlag=save[0]-48;
                saveFlag2=1;
            }

        }
        if (f==5){
            saveFunctionComputer2(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order,orderClear,undoFlag);
        }
        else if (f==11){
            saveFunctionComputer1(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order,orderClear,undoFlag);
        }

        *flagTest=0;
        *flag9=0;
    }
    else if (x==53 && y==53 && z==53 && l==53){
        printf("Are You Sure ? (Y or N) ");
        while (exitFlag2==0){
            i=0;
            exitFlag2=1;
            while ((exitFlag1=getchar())!='\n'){
                if (i<2){
                    exitFlag[i]=exitFlag1;
                    i++;
                }
            }
            exitFlag[i]='\0';
            if (exitFlag[0]=='\0' || exitFlag[0]==' ' || exitFlag[0]=='\t' || (exitFlag[0]!='n' && exitFlag[0]!='N' && exitFlag[0]!='y' && exitFlag[0]!='Y') || exitFlag[1]!='\0'){
                printf("Choose (Y or N)!!");
                exitFlag2=0;
                i=0;
            }
            else {
                exitFlag2=1;
                if (exitFlag[0]=='Y' || exitFlag[0]=='y'){
                    *flag9=2;
                }
                else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                    *flagTest=1;
                    break;
                }
            }

        }
    }
}
