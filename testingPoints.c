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


int asciiCode ( char x ){
    int q;

    q=x;

    return q;

}

/* *********************************Testing Points****************************** */

void testPointsChar (char x1[3], char y1[3], char z1[3], char l1[3], int *x, int *y, int *z, int *l, int *testFlag, int *flagTest){

    int x11,y11,z11,l11,i;
    int xx=0,yyy=0,zz=0,ll=0;
    int x1x,y1y,z1z,l1l;
    int flag=0;

    while (flag==0){
        flag=1;
        xx=0;
        yyy=0;
        zz=0;
        ll=0;
        while ((x11=getchar())!= '\n'){
            if (xx<3){
                x1[xx]=x11;
                xx++;
            }
        }
        x1[xx]='\0';
        xx=0;

        while(x1[1]!='\0' || x1[0]=='\0' || x1[0]==' ' || x1[0]=='\t'){
            printf("InValid Number\n");
            flag=0;
            break;
        }
        if (flag==0){
            continue;
        }

        while ((y11=getchar())!= '\n'){
            if (yyy<3){
                y1[yyy]=y11;
                yyy++;
            }
        }
        y1[yyy]='\0';
        yyy=0;

        while(y1[1]!='\0' || y1[0]=='\0' || y1[0]==' ' || y1[0]=='\t'){
            printf("InValid Number\n");
            flag=0;
            break;
        }
        if (flag==0){
            continue;
        }


        while ((z11=getchar())!= '\n'){
            if (zz<3){
                z1[zz]=z11;
                zz++;
            }
        }
        z1[zz]='\0';
        zz=0;

        while(z1[1]!='\0' || z1[0]=='\0' || z1[0]==' ' || z1[0]=='\t'){
            printf("InValid Number\n");
            flag=0;
            break;
        }
        if (flag==0){
            continue;
        }


        while ((l11=getchar())!= '\n'){
            if (ll<3){
                l1[ll]=l11;
                ll++;
            }
        }
        l1[ll]='\0';
        ll=0;

        while(l1[1]!='\0' || l1[0]=='\0' || l1[0]==' ' || l1[0]=='\t'){
            printf("InValid Number\n");
            flag=0;
            break;
        }
        if (flag==0){
            continue;
        }


        flagTest=1;
        x1x=asciiCode(x1[0]);
        y1y=asciiCode(y1[0]);
        z1z=asciiCode(z1[0]);
        l1l=asciiCode(l1[0]);
        *x=x1x-48;
        *y=y1y-48;
        *z=z1z-48;
        *l=l1l-48;

        if ( !isdigit(*x+48) ||  !isdigit(*y+48) ||  !isdigit(*z+48) || !isdigit(*l+48) ){
            flag=0;
        }
        if (*x==69 && *y==69 && *z==69 && *l==69){
            flag=1;
        }
        if (*x==66 && *y==66 && *z==66 && *l==66){
            flag=1;
        }
        if (*x==67 && *y==67 && *z==67 && *l==67){
            flag=1;
        }
        if (*x==53 && *y==53 && *z==53 && *l==53){
            flag=1;
        }

        if (flag==0){
            printf("(Error!)Enter a digit:");
        }

        for(i=0;i<3;i++){
            x1[i]='\0';
        }
        for(i=0;i<3;i++){
            y1[i]='\0';
        }
        for(i=0;i<3;i++){
            z1[i]='\0';
        }
        for(i=0;i<3;i++){
            l1[i]='\0';
        }
    }

}


void undoRedoSaveExitCheck (play playMatrix[11][11], char player1[], char player2[], char player[], int order, int f, int t, int *flagTest, int *flag9, int x, int y, int z, int l, int numberLines, int lineCounter, int undoScoreFlag, int undoFlag, int vs, int th, int tm,int ts,int move1, int move2,int turn, int totalScore){

    int saveFlag=0;
    char save[2];
    int temp,saveFlag2=0,exitFlag1=0,exitFlag2=0;
    char exitFlag[2];
    int i=0;

    if (x==69 && y==69 && z==69 && l==69){
        if (numberLines==lineCounter){
            *flag9=0;
            *flagTest=0;
        }
        undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
        *flag9=0;
        *flagTest=0;
    }


    else if (x==66 && y==66 && z==66 && l==66){
        if (!undoFlag){
            *flag9=0;
            *flagTest=0;
        }

        if (!abs(strcmp(player,player1))){
            redoFunction(playMatrix,f,t,order+1,player1);
        }
        else if (!abs(strcmp(player,player2))){
            redoFunction(playMatrix,f,t,order+1,player2);
        }
        *flag9=0;
        *flagTest=0;
    }


    else if (x==67 && y==67 && z==67 && l==67){
        printf("Select the save file: \n\n");
        printf("(1) Save 1\n");
        printf("(2) Save 2\n");
        printf("(3) Save 3\n");

        while (saveFlag2==0){
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
            saveFunction2(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order,undoFlag,undoScoreFlag);
        }
        else if (f==11){
            saveFunction1(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order,undoFlag,undoScoreFlag);
        }
        *flag9=0;
        *flagTest=0;
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
                    flagTest=1;
                    *flag9=3;
                    break;
                }
            }

        }
    }

}

