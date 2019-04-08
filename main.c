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


void printMainMenu (char mainMenu[]){

    int i=0,main,gameMode;

    char gameDifficulty[3];

    printf("        Dots And Boxes\n\n\n");
    printf("(1) New Game: \n\n");
    printf("(2) Load Game: \n\n");
    printf("(3) Top 10: \n\n");
    printf("(4) Exit: \n\n");
    printf("Choose: ");


    while ((gameMode=getchar())!= '\n'){
        if (i<2){
            mainMenu[i]=gameMode;
            i++;
        }
    }
    mainMenu[i]='\0';


    while ((mainMenu[0] != '1' && mainMenu[0] != '2' && mainMenu[0] != '3' && mainMenu[0] != '4') || mainMenu[1] != '\0'){
        printf("Error! Please Enter The Right Mode: ");
        i=0;
        while ((main=getchar())!= '\n'){

            if (i<2){
                mainMenu[i]=main;
                i++;
            }
        }
        mainMenu[i]='\0';

    }


    system("cls");
}

/* ************************************************************************************************************************************ */

void printSubMenu1 (char gameDifficulty[]){

    int gameMode,i=0;

    printf("(1) Beginner (2*2): \n\n");
    printf("(2) Expert (5*5): \n\n");
    printf("Choose: ");

    while ((gameMode=getchar())!= '\n'){
        if (i<2){
            gameDifficulty[i]=gameMode;
            i++;
        }
    }
    gameDifficulty[i]='\0';


    while ((gameDifficulty[0] != '1' && gameDifficulty[0] != '2') || gameDifficulty[1] != '\0'){
        i=0;
        printf("Error! Please Enter The Right Mode: ");
        while ((gameMode=getchar())!= '\n'){
            if (i<2){
                gameDifficulty[i++]=gameMode;
            }
        }
        gameDifficulty[i]='\0';
    }
    system("cls");
}

/* ************************************************************************************************************************* */

void versusSubmenu(char Vs[]){

    int versus,i=0;

    printf("(1) Vs Player: \n\n");
    printf("(2) Vs computer: \n\n");

    while ((versus=getchar())!= '\n'){
        if (i<2){
            Vs[i]=versus;
            i++;
        }
    }
    Vs[i]='\0';


    while ((Vs[0] != '1' && Vs[0] != '2') || Vs[1] != '\0'){
        i=0;
        printf("Enter The Right Mode: ");

        while ((versus=getchar())!= '\n'){
            if (i<2){
                Vs[i]=versus;
                i++;
            }
        }
        Vs[i]='\0';
    }
    system("cls");
}

/* *************************************************************************************************************************** */

int loadSubmenu(){

    int i=0,x;
    char test[3];

    printf("Select the load file:\n\n");
    printf("(1) save 1\n");
    printf("(2) save 2\n");
    printf("(3) save 3\n");

    while ((x=getchar())!= '\n'){
        if (i<2){
            test[i]=x;
            i++;
        }
    }
    test[i]='\0';

    while ((test[0] != '1' && test[0] != '2' && test[0] != '3') || test[1]!='\0'){
        i=0;
        printf("Enter The Right File: ");

        while ((x=getchar())!= '\n'){
            if (i<2){
                test[i]=x;
                i++;
            }
        }
        test[i]='\0';
    }

    i=test[0]-48;
    system("cls");

    return i;
}

/* **************************************************************************************************************************** */

void drawGrid (int n, int m){

    int i,j,k=49;
    int draw[n][m];

    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            if (i==0){
                if(j==0){
                    draw[i][j]=0;
                }
                else {
                    draw[i][j]=k;
                    draw[j][i]=k;
                    k++;
                }

            }
            else if (i!=0 && j!=0){
                k=42;
                draw[i][j]=k;
            }
        }
    }

    for (i=0;i<n;i++){
        for (j=0;j<m;j++){
            printf("%c\t",draw[i][j]);
        }
        printf("\n\n\n");
    }

}


void scoreBoard(int score1, int score2, int numberLines, char player[], char player1[], char player2[], int moves1, int moves2){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
    int originalAttrs = ConsoleInfo.wAttributes;
    printf("    Score:");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                  (%s): %d         ",player1,score1);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                   (%s): %d\n\n",player2,score2);
    SetConsoleTextAttribute(hConsole, originalAttrs);
    printf("    No. Of Moves:");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf("                   %d         ",moves1);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("                    %d\n\n",moves2);
    SetConsoleTextAttribute(hConsole, originalAttrs);
    printf("    Time:    \n\n");  //Put the time here i'm just serving the space for it
    printf("    Number of Lines Left:   %d\n\n",numberLines);
    printf("    Turn:");
    if (!abs(strcmp(player,player1))){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    }
    else if (!abs(strcmp(player,player2))){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    }
    printf("         %s\n\n",player);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("    Undo    Redo    Save    Exit\n\n");
    printf("     (u)     (r)     (s)     (e)\n\n");
    SetConsoleTextAttribute(hConsole, originalAttrs);
}


void high_score(int winnerScore, char player[17], highScoreStruct highScore[10]){


    int max=winnerScore,q,r;
    int temporary1,temporary2;
    char temporaryName1[17],temporaryName2[17];

    for (q=0;q<10;q++){
        if (max>highScore[q].score){
            temporary1=highScore[q].score;
            highScore[q].score=max;
            strcpy(temporaryName1,highScore[q].playerName);
            strcpy(highScore[q].playerName,player);

            r=q+1;

            for (r=r;r<10;r++){

                if (r==q+1){
                    temporary2=highScore[r].score;
                    strcpy(temporaryName2,highScore[r].playerName);
                    highScore[r].score=temporary1;
                    strcpy(highScore[r].playerName,temporaryName1);
                }

                else {
                    temporary1=highScore[r].score;
                    strcpy(temporaryName1,highScore[r].playerName);
                    highScore[r].score=temporary2;
                    strcpy(highScore[r].playerName,temporaryName2);
                    temporary2=temporary1;
                    strcpy(temporaryName2,temporaryName1);

                    if (r+1!=10){
                        highScore[r+1].score=temporary1;
                        strcpy(highScore[r+1].playerName,temporaryName1);
                    }
                }
            }
            break;
        }
    }
}


void high_score_print(highScoreStruct highScore[10]){

    int q,r=0;

    printf("              TOP 10:\n\n\n");

    for (q=0;q<10;q++){

        while (highScore[q].playerName[r]!='\0'){
            printf("%c",highScore[q].playerName[r]);
            r++;
        }
        r=0;
        printf("                             %d",highScore[q].score);
        printf("\n\n");

    }
}

/* ******************************************************************************************************* */

int main()
{
    char mainMenu[3],gameDifficulty[3],Vs[3],key[3];
    int load=0,modeFlag=0,f,q,r,versus=0,k,i=0,c,flag=0;
    highScoreStruct highScore[10];


/* ***********************Initializing High_score************************ */
    for (q=0;q<10;q++){
        highScore[q].score=0;
        strcpy(highScore[q].playerName,"0");
    }
/* ********************************************************************** */


    printMainMenu (mainMenu);

    while (mainMenu[0]!='4'){

        if (mainMenu[0]=='2'){

            load=loadSubmenu();


            FILE *fp;
            if (load==1){
                fp = fopen("save (1).txt","r");
                (fscanf(fp,"%d \n",&f));
                (fscanf(fp,"%d \n",&versus));
            }
            else if (load==2){
                fp = fopen("save (2).txt","r");
                (fscanf(fp,"%d \n",&f));
                (fscanf(fp,"%d \n",&versus));
            }
            else if (load==3){
                fp = fopen("save (3).txt","r");
                (fscanf(fp,"%d \n",&f));
                (fscanf(fp,"%d \n",&versus));
            }

            if (f==5){
                modeFlag=5;
            }
            else if (f==11){
                modeFlag=11;
            }

            if (versus==1){
                playFunctionComputer(gameDifficulty,mainMenu,load,modeFlag);
            }
            else if (versus==2){
                playFunction(gameDifficulty,mainMenu,load,modeFlag);
            }

            loadHighscore(highScore);

            high_score_print(highScore);

            printf("Press Enter to continue:");

            while ((k=getchar())!= '\n'){
                flag=1;
                if (i<2){
                    key[i]=k;
                    i++;
                }
            }
            key[i]='\0';


            if(flag==1){
                while(key[0] != '\0'){
                    if (flag==1){
                    printf("Error! Please Press Enter Only To Continue: ");
                    }
                    i=0;
                    while ((k=getchar())!= '\n'){
                        flag=1;
                        if (i<2){
                            key[i]=k;
                            i++;
                        }
                    }
                    key[i]='\0';
                }
            }

            system("cls");

            printMainMenu (mainMenu);

            load=0;

            continue;


        }

        else if (mainMenu[0]=='1'){

            printSubMenu1(gameDifficulty);

            versusSubmenu(Vs);

            if (Vs[0]=='1'){
                playFunction(gameDifficulty,mainMenu,load,modeFlag);
            }
            else if (Vs[0]=='2'){
                playFunctionComputer(gameDifficulty,mainMenu,load,modeFlag);
            }

            loadHighscore(highScore);

            high_score_print(highScore);

            printf("Press Enter to continue:");


            while ((k=getchar())!= '\n'){
                flag=1;
                if (i<2){
                    key[i]=k;
                    i++;
                }
            }
            key[i]='\0';


            if(flag==1){
                while(key[0] != '\0'){
                    if (flag==1){
                    printf("Error! Please Press Enter Only To Continue: ");
                    }
                    i=0;
                    while ((k=getchar())!= '\n'){
                        flag=1;
                        if (i<2){
                            key[i]=k;
                            i++;
                        }
                    }
                    key[i]='\0';
                }
            }

            system("cls");

            printMainMenu (mainMenu);

            continue;

        }

        int resetFlag;
        i=0;
        char reset[3];

/* ************************************************************************************************************************ */

        if (mainMenu[0]=='3'){

            loadHighscore(highScore);

            high_score_print(highScore);

            printf("Reset (Y or N): ");

            while ((resetFlag=getchar())!= '\n'){
                if (i<2){
                    reset[i]=resetFlag;
                    i++;
                }
            }
            reset[i]='\0';

            while ((reset[0]!='Y' && reset[0]!='y' && reset[0]!='N' && reset[0]!='n') || reset[1]=='\0' ){
                printf("Enter (Y) or (N) Only");
                while ((resetFlag=getchar())!= '\n'){
                    if (i<2){
                        reset[i++]=resetFlag;
                    }
                }
                reset[i]='\0';
            }

            if (reset[0]=='Y' || reset[0]=='y'){
                for (q=0;q<10;q++){
                    highScore[q].score=0;
                    strcpy(highScore[q].playerName,"0");
                }
                saveHighscore(highScore);
            }

            system("cls");

            printMainMenu (mainMenu);

        }
    }



    if (mainMenu[0]=='4'){

        return 0;

    }

    return 0;
}
