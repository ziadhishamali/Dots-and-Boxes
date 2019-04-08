#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include "playFunctions.h"
#include "saveFunctions.h"
#include "undoRedoFunctions.h"
#include "testingPoints.h"
#include "gettingNames.h"
#include "testingPointsComputer.h"

/**
*
*/
void playFunctionComputer (char gameDifficulty[], char mainMenu[], int loadFlag, int modeFlag){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
    int originalAttrs = ConsoleInfo.wAttributes;

    int vs=1;

    int score1=0,score2=0,turn=0,winnerScore;
    int mode;
    char player[17],player2[17],player1[17],pl,x1[3],y1[3],z1[3],l1[3];
    int numberLines,v,tm,ts,tm1,ts1,tm2,ts2,th,th2,th1,limit1,move1=0,move2=0,ai=0,totalScore=0,yy1,yy2,yy=0,xy1=0,xy2=0,chTest=0,spaceflag=0;
    int n,m,i,j,f,t,h,g,q,r=1,q1,r1,x,y,z,l;
    highScoreStruct highScore[10];
    play playMatrix[11][11];

    loadHighscore(highScore);

    int undoFlag=0;
    int undoFlag2=0;
    int undoFlag3=0,undoFlag4=0,undoFlag5=0;

    int flagger=1;
    int order=0,lineCounter=0,orderClear=0;


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


    for(i=0;i<17;i++){
        player1[i]='\0';
    }
    for(i=0;i<17;i++){
        player2[i]='\0';
    }
    for(i=0;i<17;i++){
        player[i]='\0';
    }


    if (loadFlag==0){

        playerNamesComputer(player1,player2); //getting players names

        system("cls");

        flagger=1;
        order=0,lineCounter=0;

        if (gameDifficulty[0]=='1'){
            n=m=4;
            h=g=2;
            f=t=5;
            limit1=4;
            numberLines=12;
            lineCounter=numberLines;

        }
        else if (gameDifficulty[0]=='2'){
            n=m=7;
            h=g=5;
            f=t=11;
            limit1=7;
            numberLines=60;
            lineCounter=numberLines;
        }

/* *********************************************************************************************** */
        for (i=0;i<t;i++){
            for (j=0;j<f;j++){
                if (i%2==0 && j%2==0){
                    playMatrix[i][j].line=5;
                    playMatrix[i][j].order=0;
                    strcpy(playMatrix[i][j].name,"000000000000000");
                    strcpy(playMatrix[i][j].box,"000000000000000");
                }
                else if (i%2!=0 && j%2!=0){
                    playMatrix[i][j].line=6;
                    playMatrix[i][j].order=0;
                    strcpy(playMatrix[i][j].name,"000000000000000");
                    strcpy(playMatrix[i][j].box,"000000000000000");
                }
                else {
                    playMatrix[i][j].line=0;
                    playMatrix[i][j].order=0;
                    strcpy(playMatrix[i][j].name,"000000000000000");
                    strcpy(playMatrix[i][j].box,"000000000000000");
                }
            }
        }
    }
    else {

        char pl3[17];

        if (modeFlag==5){
            f=t=5;
            n=m=4;
            limit1=4;
            loadFunctionComputer2(f,vs,playMatrix,player1,player2,pl3,&th,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order,&orderClear,&undoFlag);
            lineCounter=12;
            turn=2;

        }


        else if (modeFlag==11){
            f=t=11;
            n=m=7;
            limit1=7;
            loadFunctionComputer1(f,vs,playMatrix,player1,player2,pl3,&th,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order,&orderClear,&undoFlag);
            lineCounter=60;
            turn=2;
        }
    }

/* ************************************************************************************************** */

    srand ( time(NULL) );

    int computerPlay_counter=0;
    int sc1=0;
    int sc2=0;
    int flag1=0;
    int flag2=0;
    int load;
    int saveFlag=0;
    char save[3];

    if (loadFlag==0){

        tm1= clock()/CLOCKS_PER_SEC/60;
        ts1= clock()/CLOCKS_PER_SEC%60;
        th1= clock()/CLOCKS_PER_SEC/3600;

    }
    else{
        th1=th;
        tm1=tm;
        ts1=ts;
    }

    do {
        sc1=0;
        sc2=0;
        flag1=score1;
        flag2=score2;

        for (i=0;i<f;i++){
            for (j=0;j<t;j++){
                if (!abs(strcmp(playMatrix[i][j].box,player1)) || !abs(strcmp(playMatrix[i][j].box,player2))){
                    if (!abs(strcmp(playMatrix[i][j].box,player1))){
                        sc1++;
                    }
                    else if (!abs(strcmp(playMatrix[i][j].box,player2))){
                        sc2++;
                    }
                }
            }
        }

        score1=sc1;
        score2=sc2;

        totalScore=score1+score2;

        if (score1!=flag1 || score2!=flag2 || ai==1){
            turn++;
        }
        if (loadFlag!=0){
            turn=2;
        }

        if (turn%2==0){
            strcpy(player,player1);
        }

        else if (turn%2!=0){
            strcpy(player,player2);
        }

        ai=0;


        system("cls");

        drawGrid(n, m);         /*Drawing the grid*/



        scoreBoard(score1, score2, numberLines, player, player1, player2, move1, move2);

        if (saveFlag==1 || saveFlag==2 || saveFlag==3){
            printf("Saved Successfully!!");
        }
        saveFlag=0;

        for (i=0;i<f;i++){
            for (j=0;j<t;j++){

                if (i%2 == 0 && j%2 != 0){

                    if (playMatrix[i][j].line==1){

                        COORD newPosition = {4*(j+1)+1 , 3*(i/2+1)};
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );

                        if (!abs(strcmp(playMatrix[i][j].name,player1))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        else if (!abs(strcmp(playMatrix[i][j].name,player2))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }

                        printf("-------\a");

                    }

                }



                if (i% 2!= 0 && j%2 ==0){

                    if (playMatrix[i][j].line==1){


                        COORD newPosition = {8*(j/2+1) , 2*(i+2)-2-(i/2)};
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );

                        if (!abs(strcmp(playMatrix[i][j].name,player1))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        else if (!abs(strcmp(playMatrix[i][j].name,player2))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }

                        printf("|");


                    }
                    if (playMatrix[i][j].line==1){
                        COORD newPosition = {8*(j/2+1) , 2*(i+2)-2-(i/2)+1};
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                        printf("|\a");
                    }
                }

                    if(!abs(strcmp(playMatrix[i][j].box,player1))){
                        COORD newPosition = { (j*4)+6 , i+3+(i/2) };
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf("%c%c%c%c%c\n",219,219,219,219,219);
                        if(1){
                            COORD newPosition = {(j*4)+6 , i+3+(i/2)+1};
                            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                            printf("%c%c%c%c%c\n",219,219,219,219,219);
                        }
                    }


                    if(!abs(strcmp(playMatrix[i][j].box,player2))){
                        COORD newPosition = { (j*4)+6 ,  i+3+(i/2) };
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("%c%c%c%c%c\n",219,219,219,219,219);
                        if(1){
                           COORD newPosition = {(j*4)+6 , i+3+(i/2)+1};
                           SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                           printf("%c%c%c%c%c",219,219,219,219,219);
                        }
                    }



            }
        }

        SetConsoleTextAttribute(hConsole, originalAttrs);

        if (gameDifficulty[0]=='1'){
            COORD newPosition = { 12, 16 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }
        else if (gameDifficulty[0]=='2'){
            COORD newPosition = { 12, 25 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }

        if (modeFlag==5){
            COORD newPosition = { 12, 16 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }


        else if (modeFlag==11){
            COORD newPosition = { 12, 25 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }

        if (loadFlag==0){

            tm2= clock()/CLOCKS_PER_SEC/60;
            ts2= clock()/CLOCKS_PER_SEC%60;
            th2= clock()/CLOCKS_PER_SEC/3600;

            th=abs(th2-th1);
            tm=abs(tm2-tm1);
            ts=abs(ts2-ts1);

            if (ts<=9 && tm<=9){
                printf("0%d : 0%d : 0%d",th,tm,ts);
            }
            else if (ts<=9 && tm>9){
                printf("0%d : %d : 0%d",th,tm,ts);
            }
            else if (ts>9 && tm<=9){
                printf("0%d : 0%d : %d",th,tm,ts);
            }
            else {
                printf("0%d : %d : %d",th,tm,ts);
            }
        }

        else {

            tm2= clock()/CLOCKS_PER_SEC/60;
            ts2= clock()/CLOCKS_PER_SEC%60;
            th2= clock()/CLOCKS_PER_SEC/3600;

            th=abs(th2+th1);
            tm=abs(tm2+tm1);
            ts=abs(ts2+ts1);

            if (ts<=9 && tm<=9){
                printf("0%d : 0%d : 0%d",th,tm,ts);
            }
            else if (ts<=9 && tm>9){
                printf("0%d : %d : 0%d",th,tm,ts);
            }
            else if (ts>9 && tm<=9){
                printf("0%d : 0%d : %d",th,tm,ts);
            }
            else {
                printf("0%d : %d : %d",th,tm,ts);
            }
        }


        if (gameDifficulty[0]=='1'){
            COORD newPosition = { 0, 29 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }
        else if (gameDifficulty[0]=='2'){
            COORD newPosition = { 0, 38 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }
        if (modeFlag==5){
            COORD newPosition = { 0, 29 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }


        else if (modeFlag==11){
            COORD newPosition = { 0, 38 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }
        int temp,flagTest=1,saveFlag2=0,exitFlag1=0,exitFlag2=0;
        char exitFlag[2];


        if (numberLines==0){
            break;
        }//playFunction(gameDifficulty,mainMenu,load,modeFlag);

/* ********************************************************************************************* */

        /* Player 1 turn*/
        int testFlag=0;
        int undoScoreFlag=0,flag9=1,totalScore;
        int redoScoreFlag=0;
        int orderCopy=order;
        int flag10=0;

        if (!abs(strcmp(player,player1))){

            printf("Choose a Line:");

            testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);

            while (flagTest){
                flag9=1;
                flag10=0;
                flagTest=0;

                if (x==69 && y==69 && z==69 && l==69){
                    if (numberLines==lineCounter){
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    orderCopy=order;
                    undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
                    orderClear=(orderCopy)-(order)+1;
                    flagTest=0;
                    flag9=0;
                    break;
                }

                else if (x==66 && y==66 && z==66 && l==66){
                    if (!undoFlag){
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    if (undoFlag4==1){
                        order=0;
                    }

                    order++;
                    redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                    orderClear--;
                    if (redoScoreFlag==0){
                        order++;
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                        orderClear--;
                        while (redoScoreFlag==1){
                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            orderClear--;
                            turn=1;
                        }
                    }
                    flagTest=0;
                    flag9=0;
                    break;
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

                    flagTest=0;
                    flag9=0;
                    break;
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
                                return 0;
                            }
                            else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                                flagTest=1;
                                flag9=0;
                                break;
                            }
                        }

                    }
                }

                if (flag9==0){
                    break;
                }

                while (x>(n-1) || x<1 || y>(n-1) || y<1 || z>(n-1) || z<1 || l>(n-1) || l<1){
                    printf("(Error!) Points Not Valid\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    flag10=1;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        orderCopy=order;
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
                        orderClear=(orderCopy)-(order)+1;
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        if (undoFlag4==1){
                            order=0;
                        }

                        order++;
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        orderClear--;
                        if (redoScoreFlag==0){
                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            orderClear--;
                            while (redoScoreFlag==1){
                                order++;
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                orderClear--;
                                turn=1;
                            }
                        }
                        flagTest=0;
                        flag9=0;
                        break;
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

                        flagTest=0;
                        flag9=0;
                        break;
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
                                    return 0;
                                }
                                else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                    }
                    flagTest=1;
                    break;
                }
                if (flag9==0){
                    break;
                }
                if (flag10==1){
                    continue;
                }


/* ************************************************************************************************************ */

                while (x!=z && y!=l){
                    printf("(Error!) Don't Choose diagonal points\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    flagTest=1;
                    flag10=1;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        orderCopy=order;
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
                        orderClear=(orderCopy)-(order)+1;
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        if (undoFlag4==1){
                            order=0;
                        }

                        order++;
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        orderClear--;
                        if (redoScoreFlag==0){
                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            orderClear--;
                            while (redoScoreFlag==1){
                                order++;
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                orderClear--;
                                turn=1;
                            }
                        }
                        flagTest=0;
                        flag9=0;
                        break;
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

                        flagTest=0;
                        flag9=0;
                        break;
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
                                    return 0;
                                }
                                else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                    }
                    flagTest=1;
                    break;
                }
                if (flag9==0){
                    break;
                }
                if (flag10==1){
                    continue;
                }

/* ************************************************************************************************************** */

                while (x==z && y==l){
                    printf("(Error!) Don't Choose The Same Point\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    flagTest=1;
                    flag10=1;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        orderCopy=order;
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
                        orderClear=(orderCopy)-(order)+1;
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        if (undoFlag4==1){
                            order=0;
                        }

                        order++;
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        orderClear--;
                        if (redoScoreFlag==0){
                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            orderClear--;
                            while (redoScoreFlag==1){
                                order++;
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                orderClear--;
                                turn=1;
                            }
                        }
                        flagTest=0;
                        flag9=0;
                        break;
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

                        flagTest=0;
                        flag9=0;
                        break;
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
                                    return 0;
                                }
                                else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                    }
                    flagTest=1;
                    break;
                }
                if (flag9==0){
                    break;
                }
                if (flag10==1){
                    continue;
                }

/* ************************************************************************************************************** */

                while (abs(x-z)>1 || abs(y-l)>1){
                    printf("(Error!) Choose Two Adjacent points\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    flagTest=1;
                    flag10=1;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        orderCopy=order;
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
                        orderClear=(orderCopy)-(order)+1;
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        if (undoFlag4==1){
                            order=0;
                        }

                        order++;
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        orderClear--;
                        if (redoScoreFlag==0){
                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            orderClear--;
                            while (redoScoreFlag==1){
                                order++;
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                orderClear--;
                                turn=1;
                            }
                        }
                        flagTest=0;
                        flag9=0;
                        break;
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

                        flagTest=0;
                        flag9=0;
                        break;
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
                                    return 0;
                                }
                                else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                    }
                    flagTest=1;
                    break;
                }
                if (flag9==0){
                    break;
                }
                if (flag10==1){
                    continue;
                }

/* ************************************************************************************************************ */

                if (x==z){

                    if (l<y){
                        temp=y;
                        y=l;
                        l=temp;
                    }

                    while (playMatrix[2*(x-1)][2*(l-1)-1].line==1){
                        printf("(Error!) The Line is Played\n\n");
                        printf("Choose a Line:\n");
                        testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                        if (x==69 && y==69 && z==69 && l==69){
                            if (numberLines==lineCounter){
                                flagTest=0;
                                flag9=0;
                                break;
                            }

                            orderCopy=order;
                            undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
                            orderClear=(orderCopy)-(order)+1;
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        else if (x==66 && y==66 && z==66 && l==66){
                            if (!undoFlag){
                                flagTest=0;
                                flag9=0;
                                break;
                            }

                            if (undoFlag4==1){
                                order=0;
                            }

                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            orderClear--;
                            if (redoScoreFlag==0){
                                order++;
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                orderClear--;
                                while (redoScoreFlag==1){
                                    order++;
                                    redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                    orderClear--;
                                    turn=1;
                                }
                            }
                            flagTest=0;
                            flag9=0;
                            break;
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

                            flagTest=0;
                            flag9=0;
                            break;
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
                                        return 0;
                                    }
                                    else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                                        flagTest=1;
                                        flag9=0;
                                        break;
                                    }
                                }

                            }
                        }
                        flagTest=1;
                        flag10=1;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    if (flag10==1){
                        continue;
                    }
                }

                if (y==l){

                    if (z<x){
                        temp=x;
                        x=z;
                        z=temp;
                    }

                    while (playMatrix[2*(z-1)-1][2*(y-1)].line==1){
                        printf("(Error!) The Line is Played\n\n");
                        printf("Choose a Line:\n");
                        testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                        if (x==69 && y==69 && z==69 && l==69){
                            if (numberLines==lineCounter){
                                flagTest=0;
                                flag9=0;
                                break;
                            }

                            orderCopy=order;
                            undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);
                            orderClear=(orderCopy)-(order)+1;
                            flagTest=0;
                            flag9=0;
                            break;
                        }

                        else if (x==66 && y==66 && z==66 && l==66){
                            if (!undoFlag){
                                flagTest=0;
                                flag9=0;
                                break;
                            }

                            if (undoFlag4==1){
                                order=0;
                            }

                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            orderClear--;
                            if (redoScoreFlag==0){
                                order++;
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                orderClear--;
                                while (redoScoreFlag==1){
                                    order++;
                                    redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                    orderClear--;
                                    turn=1;
                                }
                            }
                            flagTest=0;
                            flag9=0;
                            break;
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

                            flagTest=0;
                            flag9=0;
                            break;
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
                                        return 0;
                                    }
                                    else if (exitFlag[0]=='N' || exitFlag[0]=='n'){
                                        flagTest=1;
                                        flag9=0;
                                        break;
                                    }
                                }

                            }
                        }

                        flagTest=1;
                        flag10=1;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    if (flag10==1){
                        continue;
                    }

                }
            }
            flag9=1;

            strcpy(player1,player);  //To ensure the player1 name doesn't change due to getchar

        }


        else if (!abs(strcmp(player,player2))){

    /* ***************************** AI 3 lines ****************************************************** */

        for(i=0;i<f;i++){
            if(ai==1){
                computerPlay_counter++;
                break;
            }
            for(j=0;j<t;j++){

                if(playMatrix[i][j].line == 6){
                    if(playMatrix[i+1][j].line==1 && playMatrix[i-1][j].line==1 && playMatrix[i][j+1].line==1){
                        if(playMatrix[i][j-1].line==0){
                            playMatrix[i][j-1].line=1;

                            order++;
                            playMatrix[i][j-1].order=order;
                            strcpy(playMatrix[i][j-1].name,player);
                            ai=1;

                            strcpy(playMatrix[i][j].box,player2);

                            if(playMatrix[i][j-2].line==6){
                                if(playMatrix[i-1][j-2].line==1 && playMatrix[i+1][j-2].line==1 && playMatrix[i][j-3].line==1 ){
                                    strcpy(playMatrix[i][j-2].box,player2); /*  (4) PLAYER 2    */
                                }
                            }
                            break;
                        }
                    }
                    else if(playMatrix[i+1][j].line==1 && playMatrix[i-1][j].line==1 && playMatrix[i][j-1].line==1){
                        if(playMatrix[i][j+1].line==0){
                            playMatrix[i][j+1].line=1;
                            order++;
                            playMatrix[i][j+1].order=order;
                            strcpy(playMatrix[i][j+1].name,player);
                            ai=1;

                            strcpy(playMatrix[i][j].box,player2);

                            if(playMatrix[i][j+2].line==6){
                                if(playMatrix[i-1][j+2].line==1 && playMatrix[i+1][j+2].line==1 && playMatrix[i][j+3].line==1 ){
                                    strcpy(playMatrix[i][j+2].box,player2);
                                    }
                            }
                            break;
                            }
                        }
                    else if(playMatrix[i+1][j].line==1 && playMatrix[i][j+1].line==1 && playMatrix[i][j-1].line==1){
                        if(playMatrix[i-1][j].line==0){
                            playMatrix[i-1][j].line=1;
                            order++;
                            playMatrix[i-1][j].order=order;
                            strcpy(playMatrix[i-1][j].name,player);
                            ai=1;

                            strcpy(playMatrix[i][j].box,player2);

                            if(playMatrix[i-2][j].line==6){
                                if(playMatrix[i-3][j].line==1 && playMatrix[i-2][j+1].line==1 && playMatrix[i-2][j-1].line==1 ){
                                    strcpy(playMatrix[i-2][j].box,player2);
                                }
                            }
                            break;
                        }
                    }
                    else if(playMatrix[i-1][j].line==1 && playMatrix[i][j+1].line==1 && playMatrix[i][j-1].line==1){
                        if(playMatrix[i+1][j].line==0){
                            playMatrix[i+1][j].line=1;
                            order++;
                            playMatrix[i+1][j].order=order;
                            strcpy(playMatrix[i+1][j].name,player);
                            ai=1;

                            strcpy(playMatrix[i][j].box,player2);

                            if(playMatrix[i+2][j].line==6){
                                if(playMatrix[i+3][j].line==1 && playMatrix[i+2][j+1].line==1 && playMatrix[i+2][j-1].line==1 ){
                                    strcpy(playMatrix[i+2][j].box,player2);
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }




      /* *************************************************************************************************** */

      if (ai==0){
            int flagTest=1;
            int flagTest2=1;
            int flag3=0,flag4=0,flag5=0,flag6=0;

            computerPlay_counter++;

            x= rand()%limit1;
            y= rand()%limit1;
            z= rand()%limit1;
            l= rand()%limit1;

            while (flagTest){
                flagTest=0;

                while (x>(n-1) || x<1 || y>(n-1) || y<1 || z>(n-1) || z<1 || l>(n-1) || l<1){

                    x= rand()%limit1;
                    y= rand()%limit1;
                    z= rand()%limit1;
                    l= rand()%limit1;

                    flagTest=1;
                }

                while (x!=z && y!=l){
                    x= rand()%limit1;
                    y= rand()%limit1;
                    z= rand()%limit1;
                    l= rand()%limit1;
                    flagTest=1;
                }

                while (x==z && y==l){
                    x= rand()%limit1;
                    y= rand()%limit1;
                    z= rand()%limit1;
                    l= rand()%limit1;
                    flagTest=1;
                }

                while (abs(x-z)>1 || abs(y-l)>1){
                    x= rand()%limit1;
                    y= rand()%limit1;
                    z= rand()%limit1;
                    l= rand()%limit1;
                    flagTest=1;
                }

                if (x==z){

                    if (l<y){
                        temp=y;
                        y=l;
                        l=temp;
                    }

                    while (playMatrix[2*(x-1)][2*(l-1)-1].line==1){

                        x= rand()%limit1;
                        y= rand()%limit1;
                        z= rand()%limit1;
                        l= rand()%limit1;
                        flagTest=1;
                    }
                }

                if (y==l){

                    if (z<x){
                        temp=x;
                        x=z;
                        z=temp;
                    }

                    while (playMatrix[2*(z-1)-1][2*(y-1)].line==1){

                        x= rand()%limit1;
                        y= rand()%limit1;
                        z= rand()%limit1;
                        l= rand()%limit1;
                        flagTest=1;
                    }
                }


            }

      }



    }
    int fl=0,k=1;
    if (!abs(strcmp(player,player1))){
        if ((x!=69 && y!=69 && z!=69 && l!=69) && (x!=66 && y!=66 && z!=66 && l!=66) && (x!=67 && y!=67 && z!=67 && l!=67) && (x!=53 && y!=53 && z!=53 && l!=53)){
            while (k<=orderClear){
                for (i=0;i<f;i++){
                    for (j=0;j<t;j++){
                        if (playMatrix[i][j].order==order+k){
                            playMatrix[i][j].order=0;
                            i=0;
                            j=0;
                            fl=1;
                            k++;
                            break;
                        }
                    }
                    if (fl==1){
                        fl=0;
                        break;
                    }
                }
            }
            orderClear=0;
            undoFlag=0;
        }
    }

        if (x==69 && y==69 && z==69 && l==69){
            undoFlag++;
            undoFlag3=0;
            if (numberLines==lineCounter){
                undoFlag4=1;
                undoFlag5=0;
                order--;
                continue;
            }
            order--;
            continue;
        }

        else if (x==66 && y==66 && z==66 && l==66){
            if(!undoFlag){
                continue;
            }
            if (undoFlag4==1){
                undoFlag4=0;
                undoFlag5=1;
            }
            undoFlag--;
            continue;
        }
        else if (x==67 && y==67 && z==67 && l==67){
            continue;
        }
        else if (x==53 && y==53 && z==53 && l==53){
            continue;
        }

    if (ai==0){
        if (x==z){
            order++;
            playMatrix[2*(x-1)][2*(l-1)-1].line=1;
            playMatrix[2*(x-1)][2*(l-1)-1].order=order;
            strcpy(playMatrix[2*(x-1)][2*(l-1)-1].name,player);

        }

        else if (y==l){
            order++;
            playMatrix[2*(z-1)-1][2*(y-1)].line=1;
            playMatrix[2*(z-1)-1][2*(y-1)].order=order;
            strcpy(playMatrix[2*(z-1)-1][2*(y-1)].name,player);

        }

    }


        /* *************************************************************************** */

        /*        Horizontal     */

    if (ai==0){

        if (x==z){

            if (playMatrix[2*(x-1)-1][2*(l-1)-1].line==6){

                if (playMatrix[2*(x-1)-1][2*(l-1)-1+1].line==1 && playMatrix[2*(x-1)-1][2*(l-1)-1-1].line==1 && playMatrix[2*(x-1)-1+1][2*(l-1)-1].line==1 && playMatrix[2*(x-1)-1-1][2*(l-1)-1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(x-1)-1][2*(l-1)-1].box,player1);


                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(x-1)-1][2*(l-1)-1].box,player2);


                    }
                }

            }


            if (playMatrix[2*(x-1)+1][2*(l-1)-1].line==6){

                if (playMatrix[2*(x-1)+1][2*(l-1)-1+1].line==1 && playMatrix[2*(x-1)+1][2*(l-1)-1-1].line==1 && playMatrix[2*(x-1)+1+1][2*(l-1)-1].line==1 && playMatrix[2*(x-1)+1-1][2*(l-1)-1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(x-1)+1][2*(l-1)-1].box,player1);



                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(x-1)+1][2*(l-1)-1].box,player2);



                    }
                }

            }

        }


        /*                 Vertical        */

        if (y==l){

            if (playMatrix[2*(z-1)-1][2*(y-1)+1].line==6){

                if (playMatrix[2*(z-1)-1][2*(y-1)+1+1].line==1 && playMatrix[2*(z-1)-1][2*(y-1)+1-1].line==1 && playMatrix[2*(z-1)-1+1][2*(y-1)+1].line==1 && playMatrix[2*(z-1)-1-1][2*(y-1)+1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)+1].box,player1);


                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)+1].box,player2);


                    }
                }

            }

             if (playMatrix[2*(z-1)-1][2*(y-1)-1].line==6){

                if (playMatrix[2*(z-1)-1][2*(y-1)-1+1].line==1 && playMatrix[2*(z-1)-1][2*(y-1)-1-1].line==1 && playMatrix[2*(z-1)-1+1][2*(y-1)-1].line==1 && playMatrix[2*(z-1)-1-1][2*(y-1)-1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)-1].box,player1);


                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)-1].box,player2);


                    }
                }

            }

        }
    }


        if (!abs(strcmp(player,player1))){
            move1++;
        }
        else if (!abs(strcmp(player,player2))){
            move2++;
        }

        turn++;
        numberLines--;

        if (f==5){
            saveFunctionComputer2(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,0,order,orderClear,undoFlag);
        }
        else if (f==11){
            saveFunctionComputer1(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,0,order,orderClear,undoFlag);
        }

    }
    while (numberLines!=-1);

    system("cls");

    if (score1>score2){

        printf("Congratulations!! %s You Won\n\n",player1);
        winnerScore=score1;
        high_score(winnerScore,player1,highScore);
        saveHighscore(highScore);
    }
    else if (score2>score1){

        printf("Sorry!! %s You Lost, Don't Give Up\n\n",player1);
        winnerScore=score2;
        high_score(winnerScore,player2,highScore);
        saveHighscore(highScore);
    }
    else if (score1==score2){

        printf("OH! You Almost won but Game Drawn!!");
    }

}



void playFunction (char gameDifficulty[], char mainMenu[], int loadFlag, int modeFlag){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
    int originalAttrs = ConsoleInfo.wAttributes;

    int vs=2;

    int score1=0,score2=0,turn=0,winnerScore;
    int mode;
    char player[17],player2[17],player1[17],pl[17],x1[3],y1[3],z1[3],l1[3];
    int numberLines,x,y,z,l,v,tm,ts,tm1,ts1,tm2,ts2,th,th2,th1,move1=0,move2=0,yy1,yy2,yy=0,xy1=0,xy2=0,chTest=0,spaceFlag1=0,spaceFlag2=0;
    int x11,y11,z11,l11,xx=0,yyy=0,zz=0,ll=0,x1x,y1y,z1z,l1l;
    int n,m,i,j,k,f,t,h,g,q,r=1,q1,r1,testFlag,totalScore=0;
    highScoreStruct highScore[10];
    play playMatrix[11][11];

    int undoScoreFlag=0;
    int undoFlag=0;

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


    for (i=0;i<17;i++){
        player1[i]='\0';
    }
    for (i=0;i<17;i++){
        player2[i]='\0';
    }
    for (i=0;i<17;i++){
        player[i]='\0';
    }

    loadHighscore(highScore);

    int flagger=1;
    int order,lineCounter;

    if (loadFlag==0){

        playerNames(player1,player2); //getting players names

        system("cls");

        flagger=1;
        order=0,lineCounter=0;

        if (gameDifficulty[0]=='1'){
            n=m=4;
            h=g=2;
            f=t=5;
            numberLines=12;
            lineCounter=numberLines;

        }
        else if (gameDifficulty[0]=='2'){
            n=m=7;
            h=g=5;
            f=t=11;
            numberLines=60;
            lineCounter=numberLines;
        }

/* *********************************************************************************************** */
    for (i=0;i<t;i++){
        for (j=0;j<f;j++){
            if (i%2==0 && j%2==0){
                playMatrix[i][j].line=5;
                playMatrix[i][j].order=0;
                strcpy(playMatrix[i][j].name,"000000000000000");
                strcpy(playMatrix[i][j].box,"000000000000000");
            }
            else if (i%2!=0 && j%2!=0){
                playMatrix[i][j].line=6;
                playMatrix[i][j].order=0;
                strcpy(playMatrix[i][j].name,"000000000000000");
                strcpy(playMatrix[i][j].box,"000000000000000");
            }
            else {
                playMatrix[i][j].line=0;
                playMatrix[i][j].order=0;
                strcpy(playMatrix[i][j].name,"000000000000000");
                strcpy(playMatrix[i][j].box,"000000000000000");
            }
        }
    }
    }
    else {

        char pl3[16];

        if (modeFlag==5){
            f=t=5;
            n=m=4;
            loadFunction2(f,vs,playMatrix,player1,player2,pl3,&th,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order,&undoFlag,&undoScoreFlag);
            lineCounter=12;

            if (totalScore%2==0){
                turn+=totalScore/2;
            }
            else if (totalScore%2!=0){
                turn+=totalScore%2;
            }

        }


        else if (modeFlag==11){
            f=t=11;
            n=m=7;
            loadFunction1(f,vs,playMatrix,player1,player2,pl3,&th,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order,&undoFlag,&undoScoreFlag);
            lineCounter=60;

            if (totalScore%2==0){
                turn+=totalScore/2;
            }
            else if (totalScore%2!=0){
                turn+=totalScore%2;
            }
        }
    }



/* ************************************************************************************************** */
    char undo;
    int sc1=0;
    int sc2=0;
    int flag1=0;
    int flag2=0;
    int flag9=1;
    int flag10=1;
    int saveFlag=0;
    char save[2];

    if (loadFlag==0){

        tm1= clock()/CLOCKS_PER_SEC/60;
        ts1= clock()/CLOCKS_PER_SEC%60;
        th1= clock()/CLOCKS_PER_SEC/3600;

    }
    else{
        th1=th;
        tm1=tm;
        ts1=ts;
    }

    do {
        sc1=0;
        sc2=0;
        flag1=score1;
        flag2=score2;
        chTest=0;

        for (i=0;i<f;i++){
            for (j=0;j<t;j++){
                if (!abs(strcmp(playMatrix[i][j].box,player1)) || !abs(strcmp(playMatrix[i][j].box,player2))){
                    if (!strcmp(playMatrix[i][j].box,player1)){
                        sc1++;
                    }
                    else if (!abs(strcmp(playMatrix[i][j].box,player2))){
                        sc2++;
                    }
                }
            }
        }

        score1=sc1;
        score2=sc2;

        totalScore=score1+score2;

        if (score1!=flag1 || score2!=flag2){
            turn++;
        }

        if (turn%2==0){
            strcpy(player,player1);
        }

        else if (turn%2!=0){
            strcpy(player,player2);
        }


        system("cls");

        drawGrid(n, m);         /*Drawing the grid*/



        scoreBoard(score1, score2, numberLines, player, player1, player2, move1, move2);

        if (saveFlag==1 || saveFlag==2 || saveFlag==3){
            printf("Saved Successfully!!");
        }
        saveFlag=0;

        for (i=0;i<f;i++){
            for (j=0;j<t;j++){

                if (i%2 == 0 && j%2 != 0){

                    if (playMatrix[i][j].line==1){

                        COORD newPosition = {4*(j+1)+1 , 3*(i/2+1)};
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );

                        if (!abs(strcmp(playMatrix[i][j].name,player1))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        else if (!abs(strcmp(playMatrix[i][j].name,player2))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }

                        printf("-------\a");

                    }

                }



                if (i% 2!= 0 && j%2 ==0){

                    if (playMatrix[i][j].line==1){


                        COORD newPosition = {8*(j/2+1) , 2*(i+2)-2-(i/2)};
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );

                        if (!abs(strcmp(playMatrix[i][j].name,player1))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        }
                        else if (!abs(strcmp(playMatrix[i][j].name,player2))){
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        }

                        printf("|");


                    }
                    if (playMatrix[i][j].line==1){
                        COORD newPosition = {8*(j/2+1) , 2*(i+2)-2-(i/2)+1};
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                        printf("|\a");
                    }
                }

                    if(!abs(strcmp(playMatrix[i][j].box,player1))){
                        COORD newPosition = { (j*4)+6 , i+3+(i/2) };
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                        printf("%c%c%c%c%c\n",219,219,219,219,219);
                        if(1){
                            COORD newPosition = {(j*4)+6 , i+3+(i/2)+1};
                            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                            printf("%c%c%c%c%c\n",219,219,219,219,219);
                        }
                    }


                    if(!abs(strcmp(playMatrix[i][j].box,player2))){
                        COORD newPosition = { (j*4)+6 ,  i+3+(i/2) };
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                        printf("%c%c%c%c%c\n",219,219,219,219,219);
                        if(1){
                           COORD newPosition = {(j*4)+6 , i+3+(i/2)+1};
                           SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
                           printf("%c%c%c%c%c",219,219,219,219,219);
                        }
                    }



            }
        }

        SetConsoleTextAttribute(hConsole, originalAttrs);

        if (gameDifficulty[0]=='1'){
            COORD newPosition = { 12, 16 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }
        else if (gameDifficulty[0]=='2'){
            COORD newPosition = { 12, 25 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }

        if (modeFlag==5){
            COORD newPosition = { 12, 16 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }


        else if (modeFlag==11){
            COORD newPosition = { 12, 25 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }

        if (loadFlag==0){

            tm2= clock()/CLOCKS_PER_SEC/60;
            ts2= clock()/CLOCKS_PER_SEC%60;
            th2= clock()/CLOCKS_PER_SEC/3600;

            th=abs(th2-th1);
            tm=abs(tm2-tm1);
            ts=abs(ts2-ts1);

            if (ts<=9 && tm<=9){
                printf("0%d : 0%d : 0%d",th,tm,ts);
            }
            else if (ts<=9 && tm>9){
                printf("0%d : %d : 0%d",th,tm,ts);
            }
            else if (ts>9 && tm<=9){
                printf("0%d : 0%d : %d",th,tm,ts);
            }
            else {
                printf("0%d : %d : %d",th,tm,ts);
            }
        }

        else {

            tm2= clock()/CLOCKS_PER_SEC/60;
            ts2= clock()/CLOCKS_PER_SEC%60;
            th2= clock()/CLOCKS_PER_SEC/3600;

            th=abs(th2+th1);
            tm=abs(tm2+tm1);
            ts=abs(ts2+ts1);

            if (ts<=9 && tm<=9){
                printf("0%d : 0%d : 0%d",th,tm,ts);
            }
            else if (ts<=9 && tm>9){
                printf("0%d : %d : 0%d",th,tm,ts);
            }
            else if (ts>9 && tm<=9){
                printf("0%d : 0%d : %d",th,tm,ts);
            }
            else {
                printf("0%d : %d : %d",th,tm,ts);
            }
        }




        if (gameDifficulty[0]=='1'){
            COORD newPosition = { 0, 29 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }
        else if (gameDifficulty[0]=='2'){
            COORD newPosition = { 0, 38 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }
        if (modeFlag==5){
            COORD newPosition = { 0, 29 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }


        else if (modeFlag==11){
            COORD newPosition = { 0, 38 };
            SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), newPosition );
        }


        int temp,flagTest=1,saveFlag2=0,exitFlag1=0,exitFlag2=0;
        char exitFlag[2];
        i=0;

        if (numberLines==0){
            break;
        }
            printf("Choose a Line:");

            testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);

            while (flagTest){
                flagTest=0;
                flag9=1;
                flag10=0;
                undoRedoSaveExitCheck(playMatrix,player1,player2,player,order,f,t,&flagTest,&flag9,x,y,z,l,numberLines,lineCounter,undoScoreFlag,undoFlag,vs,th,tm,ts,move1,move2,turn,totalScore);

                if (flag9==2){
                    return 0;
                }
                if (flag9==0 || flag9==3){
                    break;
                }

/* ************************************************************************************************************ */

                while (x>(n-1) || x<1 || y>(n-1) || y<1 || z>(n-1) || z<1 || l>(n-1) || l<1){
                    printf("(Error!) Points Not Valid\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    undoRedoSaveExitCheck(playMatrix,player1,player2,player,order,f,t,&flagTest,&flag9,x,y,z,l,numberLines,lineCounter,undoScoreFlag,undoFlag,vs,th,tm,ts,move1,move2,turn,totalScore);
                    flagTest=1;
                    flag10=1;
                    break;
                }
                if (flag9==3){
                    break;
                }
                if (flag9==2){
                    return 0;
                }
                if (flag9==0){
                    break;
                }

                if (flag10==1){
                    flag10=0;
                    continue;
                }



/* ************************************************************************************************************ */

                while (x!=z && y!=l){
                    printf("(Error!) Don't Choose diagonal points\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    undoRedoSaveExitCheck(playMatrix,player1,player2,player,order,f,t,&flagTest,&flag9,x,y,z,l,numberLines,lineCounter,undoScoreFlag,undoFlag,vs,th,tm,ts,move1,move2,turn,totalScore);
                    flagTest=1;
                    flag10=1;
                    break;

                }
                if (flag9==3){
                    break;
                }
                if (flag9==2){
                    return 0;
                }
                if (flag9==0){
                    break;
                }

                if (flag10==1){
                    flag10=0;
                    continue;
                }

/* ************************************************************************************************************** */

                while (x==z && y==l){
                    printf("(Error!) Don't Choose The Same Point\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    undoRedoSaveExitCheck(playMatrix,player1,player2,player,order,f,t,&flagTest,&flag9,x,y,z,l,numberLines,lineCounter,undoScoreFlag,undoFlag,vs,th,tm,ts,move1,move2,turn,totalScore);
                    flagTest=1;
                    flag10=1;
                    break;
                }
                if (flag9==3){
                    break;
                }
                if (flag9==2){
                    return 0;
                }
                if (flag9==0){
                    break;
                }

                if (flag10==1){
                    flag10=0;
                    continue;
                }
/* ************************************************************************************************************** */

                while (abs(x-z)>1 || abs(y-l)>1){
                    printf("(Error!) Choose Two Adjacent points\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    undoRedoSaveExitCheck(playMatrix,player1,player2,player,order,f,t,&flagTest,&flag9,x,y,z,l,numberLines,lineCounter,undoScoreFlag,undoFlag,vs,th,tm,ts,move1,move2,turn,totalScore);
                    flagTest=1;
                    flag10=1;
                    break;
                }
                if (flag9==3){
                    break;
                }
                if (flag9==2){
                    return 0;
                }
                if (flag9==0){
                    break;
                }

                if (flag10==1){
                    flag10=0;
                    continue;
                }
/* ************************************************************************************************************ */

                if (x==z){

                    if (l<y){
                        temp=y;
                        y=l;
                        l=temp;
                    }

                    while (playMatrix[2*(x-1)][2*(l-1)-1].line==1){
                        printf("(Error!) The Line is Played\n\n");
                        printf("Choose a Line:\n");
                        testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                        undoRedoSaveExitCheck(playMatrix,player1,player2,player,order,f,t,&flagTest,&flag9,x,y,z,l,numberLines,lineCounter,undoScoreFlag,undoFlag,vs,th,tm,ts,move1,move2,turn,totalScore);
                        flagTest=1;
                        flag10=1;
                        break;
                    }
                    if (flag9==3){
                        break;
                    }
                    if (flag9==2){
                        return 0;
                    }
                    if (flag9==0){
                        break;
                    }

                    if (flag10==1){
                        flag10=0;
                        continue;
                    }
                }

                if (y==l){

                    if (z<x){
                        temp=x;
                        x=z;
                        z=temp;
                    }

                    while (playMatrix[2*(z-1)-1][2*(y-1)].line==1){
                        printf("(Error!) The Line is Played\n\n");
                        printf("Choose a Line:\n");
                        testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                        undoRedoSaveExitCheck(playMatrix,player1,player2,player,order,f,t,&flagTest,&flag9,x,y,z,l,numberLines,lineCounter,undoScoreFlag,undoFlag,vs,th,tm,ts,move1,move2,turn,totalScore);
                        flagTest=1;
                        flag10=1;
                        break;
                    }
                    if (flag9==3){
                        break;
                    }
                    if (flag9==2){
                        return 0;
                    }
                    if (flag9==0){
                        break;
                    }

                    if (flag10==1){
                        flag10=0;
                        continue;
                    }

                }

            }
            flag9=1;

        if ((x!=69 && y!=69 && z!=69 && l!=69) && (x!=66 && y!=66 && z!=66 && l!=66) && (x!=67 && y!=67 && z!=67 && l!=67) && (x!=53 && y!=53 && z!=53 && l!=53)){
            for (i=0;i<f;i++){
                for (j=0;j<t;j++){
                    if (playMatrix[i][j].order==order+1){
                        playMatrix[i][j].order=0;
                    }
                }
            }
            undoFlag=0;
        }

        if (x==69 && y==69 && z==69 && l==69){
            if (numberLines==lineCounter){
                continue;
            }
            order--;
            numberLines++;
            undoFlag++;
            turn++;
            if (undoScoreFlag==1){
                if (!abs(strcmp(player,player1))){
                    move1--;
                }
                else if (!abs(strcmp(player,player2))){
                    move2--;
                }
            }
            else if (undoScoreFlag==0){
                if (!abs(strcmp(player,player1))){
                    move2--;
                }
                else if (!abs(strcmp(player,player2))){
                    move1--;
                }
            }
            continue;
        }

        else if (x==66 && y==66 && z==66 && l==66){
            if(!undoFlag){
                continue;
            }
            order++;
            undoFlag--;
            numberLines--;
            turn++;
            if (!abs(strcmp(player,player1))){
                move1++;
            }
            else if (!abs(strcmp(player,player2))){
                move2++;
            }
            continue;
        }
        else if (x==67 && y==67 && z==67 && l==67){
            continue;
        }
        else if (x==53 && y==53 && z==53 && l==53){
            continue;
        }


        if (x==z){
            order++;
            playMatrix[2*(x-1)][2*(l-1)-1].line=1;
            strcpy(playMatrix[2*(x-1)][2*(l-1)-1].name,player);
            playMatrix[2*(x-1)][2*(l-1)-1].order=order;

        }

        else if (y==l){
            order++;
            playMatrix[2*(z-1)-1][2*(y-1)].line=1;
            strcpy(playMatrix[2*(z-1)-1][2*(y-1)].name,player);
            playMatrix[2*(z-1)-1][2*(y-1)].order=order;

        }




        /* *************************************************************************** */

        /*        Horizontal     */



        if (x==z){

            if (playMatrix[2*(x-1)-1][2*(l-1)-1].line==6){

                if (playMatrix[2*(x-1)-1][2*(l-1)-1+1].line==1 && playMatrix[2*(x-1)-1][2*(l-1)-1-1].line==1 && playMatrix[2*(x-1)-1+1][2*(l-1)-1].line==1 && playMatrix[2*(x-1)-1-1][2*(l-1)-1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(x-1)-1][2*(l-1)-1].box,player1);


                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(x-1)-1][2*(l-1)-1].box,player2);


                    }
                }

            }


            if (playMatrix[2*(x-1)+1][2*(l-1)-1].line==6){

                if (playMatrix[2*(x-1)+1][2*(l-1)-1+1].line==1 && playMatrix[2*(x-1)+1][2*(l-1)-1-1].line==1 && playMatrix[2*(x-1)+1+1][2*(l-1)-1].line==1 && playMatrix[2*(x-1)+1-1][2*(l-1)-1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(x-1)+1][2*(l-1)-1].box,player1);


                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(x-1)+1][2*(l-1)-1].box,player2);



                    }
                }

            }

        }


        /*                 Vertical        */

        if (y==l){

            if (playMatrix[2*(z-1)-1][2*(y-1)+1].line==6){

                if (playMatrix[2*(z-1)-1][2*(y-1)+1+1].line==1 && playMatrix[2*(z-1)-1][2*(y-1)+1-1].line==1 && playMatrix[2*(z-1)-1+1][2*(y-1)+1].line==1 && playMatrix[2*(z-1)-1-1][2*(y-1)+1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)+1].box,player1);


                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)+1].box,player2);


                    }
                }

            }

             if (playMatrix[2*(z-1)-1][2*(y-1)-1].line==6){

                if (playMatrix[2*(z-1)-1][2*(y-1)-1+1].line==1 && playMatrix[2*(z-1)-1][2*(y-1)-1-1].line==1 && playMatrix[2*(z-1)-1+1][2*(y-1)-1].line==1 && playMatrix[2*(z-1)-1-1][2*(y-1)-1].line==1){

                    if (!abs(strcmp(player,player1))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)-1].box,player1);


                    }
                    else if (!abs(strcmp(player,player2))){

                        strcpy(playMatrix[2*(z-1)-1][2*(y-1)-1].box,player2);


                    }
                }

            }

        }


        if (!abs(strcmp(player,player1))){
            move1++;
        }
        else if (!abs(strcmp(player,player2))){
            move2++;
        }

        turn++;
        numberLines--;

        if (f==5){
            saveFunction2(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,0,order,undoFlag,undoScoreFlag);
        }
        else if (f==11){
            saveFunction1(f,vs,playMatrix,player1,player2,player,th,tm,ts,move1,move2,numberLines,turn,totalScore,0,order,undoFlag,undoScoreFlag);
        }
    }
    while (numberLines!=-1);

    system("cls");

    if (score1>score2){

        printf("Congratulations!! %s Won\n\n",player1);
        winnerScore=score1;
        high_score(winnerScore,player1,highScore);
        saveHighscore(highScore);
    }
    else if (score2>score1){

        printf("Congratulations!! %s Won\n\n",player2);
        winnerScore=score2;
        high_score(winnerScore,player2,highScore);
        saveHighscore(highScore);
    }
    else if (score1==score2){

        printf("OH! You both Were close but Game Drawn!!/n");
    }

}
