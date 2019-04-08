void playFunction (char gameDifficulty[], char mainMenu[], int loadFlag, int modeFlag){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
    int originalAttrs = ConsoleInfo.wAttributes;

    int vs=2;

    int score1=0,score2=0,turn=0,winnerScore;
    int mode;
    char player[16],player2[16],player1[16],pl[2],x1[2],y1[2],z1[2],l1[2];
    int numberLines,x,y,z,l,v,tm,ts,tm1,ts1,tm2,ts2,move1=0,move2=0,yy1,yy2,yy=0,xy1=0,xy2=0,chTest=0;
    int x11,y11,z11,l11,xx=0,yyy=0,zz=0,ll=0,x1x,y1y,z1z,l1l;
    int n,m,i,j,k,f,t,h,g,q,r=1,q1,r1,testFlag,totalScore=0;
    highScoreStruct highScore[10];
    play playMatrix[11][11];





    loadHighscore(highScore);

    int flagger=1;
    int order,lineCounter;


    for(i=0;i<16;i++){
        player1[i]='\0';
    }
    for(i=0;i<16;i++){
        player2[i]='\0';
    }



    if (loadFlag==0){
/* ************************************PLAYER1 NAME*************************************************************************** */
        printf("Enter Player 1 Name (Max 15): ");

        while ((yy1=getchar()) != '\n'){
            if(yy<16){
                player1[yy]=yy1;
                yy++;
            }
            player1[yy]='\0';
        }

        while(player1[0] == ' ' || player1[0]=='\0' || player1[0]=='0'){

            printf("UnAccepted Name\n");
            yy=0;
            printf("Enter Player 1 Name (Max 15): ");

            while ((yy1=getchar()) != '\n'){
                if(yy<16){
                    player1[yy]=yy1;
                    yy++;
                }
                player1[yy]='\0';
            }
        }

        while(player1[15] != '\0'){
            if(xy1==1){
                break;
            }
            printf("UnAccepted Name\n");
            yy=0;
            printf("Enter Player 1 Name (Max 15): ");

            while ((yy1=getchar()) != '\n'){
                if(yy<16){
                    player1[yy]=yy1;
                    yy++;
                }
                player1[yy]='\0';
            }

                if(yy<16){
                    xy1=1;
                }

        }

        while(player1[0] == ' ' || player1[0]=='\0' || player1[0]=='0'){

            printf("UnAccepted Name\n");
            yy=0;
            printf("Enter Player 1 Name (Max 15): ");

            while ((yy1=getchar()) != '\n'){
                if(yy<16){
                    player1[yy]=yy1;
                    yy++;
                }
                player1[yy]='\0';
            }
        }
/* ************************************PLAYER2 NAME**************************************************************************************/

        printf("Enter Player 2 Name (Max 15): ");
        yy=0;

        while ((yy2=getchar()) != '\n'){
            if(yy<16){
                player2[yy]=yy2;
                yy++;
            }
            player2[yy]='\0';
        }


        while(player2[0] == ' ' || player2[0]=='\0' || player2[0]=='0'){

            printf("UnAccepted Name\n");
            yy=0;
            printf("Enter Player 2 Name (Max 15): ");


            while ((yy2=getchar()) != '\n'){
                if(yy<16){
                    player2[yy]=yy2;
                    yy++;
                }
                player2[yy]='\0';
            }
        }

        while(player2[15] != '\0'){
            if(xy2==1){
                break;
            }
            printf("UnAccepted Name\n");
            yy=0;
            printf("Enter Player 2 Name (Max 15): ");


            while ((yy2=getchar()) != '\n'){
                if(yy<16){
                    player2[yy]=yy2;
                    yy++;
                }
                player2[yy]='\0';
            }
                if(yy<16){
                    xy2=1;
                }
        }


        while(player2[0] == ' ' || player2[0]=='\0' || player2[0]=='0'){

            printf("UnAccepted Name\n");
            yy=0;
            printf("Enter Player 2 Name (Max 15): ");


            while ((yy2=getchar()) != '\n'){
                if(yy<16){
                    player2[yy]=yy2;
                    yy++;
                }
                player2[yy]='\0';
            }
        }
/* ********************************************************************************************************************** */

        system("cls");

        tm1= clock()/CLOCKS_PER_SEC/60;
        ts1= clock()/CLOCKS_PER_SEC%60;

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

        tm1= clock()/CLOCKS_PER_SEC/60;
        ts1= clock()/CLOCKS_PER_SEC%60;

        if (modeFlag==5){
            f=t=5;
            n=m=4;
            loadFunction2(f,vs,playMatrix,player1,player2,pl3,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order);
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
            loadFunction1(f,vs,playMatrix,player1,player2,pl3,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order);
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
    int undoScoreFlag=0;

/* ************************************************************************************************** */
    int undoFlag=0;
    int sc1=0;
    int sc2=0;
    int flag1=0;
    int flag2=0;
    int flag9=1;
    int saveFlag=0;
    char save[2];

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
                    else if (!strcmp(playMatrix[i][j].box,player2)){
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

                    if(!strcmp(playMatrix[i][j].box,player1)){
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


                    if(!strcmp(playMatrix[i][j].box,player2)){
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


        tm2= clock()/CLOCKS_PER_SEC/60;
        ts2= clock()/CLOCKS_PER_SEC%60;

        tm=abs(tm2-tm1);
        ts=abs(ts2-ts1);

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

        if (ts<=9 && tm<=9){
            printf("0%d : 0%d",tm,ts);
        }
        if (ts<=9 && tm>9){
            printf("%d : 0%d",tm,ts);
        }
        if (ts>9 && t<=9){
            printf("0%d : %d",tm,ts);
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
                flag9=1;
                flagTest=0;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flag9=0;
                            flagTest=0;
                            break;
                        }
                        undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
                        flagTest=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flag9=0;
                            flagTest=0;
                            break;
                        }

                        if (!abs(strcmp(player,player1))){
                            redoFunction(playMatrix,f,t,order+1,player1);
                        }
                        else if (!abs(strcmp(player,player2))){
                            redoFunction(playMatrix,f,t,order+1,player2);
                        }

                        flagTest=0;
                        break;
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
                            saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                        }
                        else if (f==11){
                            saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                        }
                        flagTest=0;
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
                                    break;
                                }
                            }

                        }
                    }

/* *************************************************************************************************************** */

                while (x>(n-1) || x<1 || y>(n-1) || y<1 || z>(n-1) || z<1 || l>(n-1) || l<1){
                    printf("(Error!) Points Not Valid\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flag9=0;
                            flagTest=0;
                            break;
                        }
                        undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flag9=0;
                            flagTest=0;
                            break;
                        }

                        if (!abs(strcmp(player,player1))){
                            redoFunction(playMatrix,f,t,order+1,player1);
                        }
                        else if (!abs(strcmp(player,player2))){
                            redoFunction(playMatrix,f,t,order+1,player2);
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
                            saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                        }
                        else if (f==11){
                            saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
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
                                else if(exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }

                    }

                    flagTest=1;
                }
                if (flag9==0){
                    flag9=1;
                    break;
                }


/* ************************************************************************************************************ */

                while (x!=z && y!=l){
                    printf("(Error!) Don't Choose diagonal points\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    flagTest=1;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flag9=0;
                            flagTest=0;
                            break;
                        }
                        undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flag9=0;
                            flagTest=0;
                            break;
                        }

                        if (!abs(strcmp(player,player1))){
                            redoFunction(playMatrix,f,t,order+1,player1);
                        }
                        else if (!abs(strcmp(player,player2))){
                            redoFunction(playMatrix,f,t,order+1,player2);
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
                            saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                        }
                        else if (f==11){
                            saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
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
                                else if(exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                    }
                    flagTest=1;
                }
                if (flag9==0){
                    flag9=1;
                    break;
                }

/* ************************************************************************************************************** */

                while (x==z && y==l){
                    printf("(Error!) Don't Choose The Same Point\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    flagTest=1;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flag9=0;
                            flagTest=0;
                            break;
                        }
                        undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flag9=0;
                            flagTest=0;
                            break;
                        }

                        if (!abs(strcmp(player,player1))){
                            redoFunction(playMatrix,f,t,order+1,player1);
                        }
                        else if (!abs(strcmp(player,player2))){
                            redoFunction(playMatrix,f,t,order+1,player2);
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
                            saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                        }
                        else if (f==11){
                            saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
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
                                else if(exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                    }

                    }
                    if (flag9==0){
                        flag9=1;
                        break;
                    }

/* ************************************************************************************************************** */

                while (abs(x-z)>1 || abs(y-l)>1){
                    printf("(Error!) Choose Two Adjacent points\n\n");
                    printf("Choose a Line:\n");
                    testPointsChar(x1,y1,z1,l1,&x,&y,&z,&l,&testFlag,&flagTest);
                    flagTest=1;
                }
                if (x==69 && y==69 && z==69 && l==69){
                    if (numberLines==lineCounter){
                        flag9=0;
                        flagTest=0;
                        break;
                    }
                    undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
                    flagTest=0;
                    flag9=0;
                    break;
                }

                else if (x==66 && y==66 && z==66 && l==66){
                    if (!undoFlag){
                        flag9=0;
                        flagTest=0;
                        break;
                    }

                    if (!abs(strcmp(player,player1))){
                        redoFunction(playMatrix,f,t,order+1,player1);
                    }
                    else if (!abs(strcmp(player,player2))){
                        redoFunction(playMatrix,f,t,order+1,player2);
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
                        saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                    }
                    else if (f==11){
                        saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
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
                                else if(exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                }

                if (flag9==0){
                    flag9=1;
                    break;
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
                        flagTest=1;
                        break;
                    }
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flag9=0;
                            flagTest=0;
                            break;
                        }
                        undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flag9=0;
                            flagTest=0;
                            break;
                        }

                        if (!abs(strcmp(player,player1))){
                            redoFunction(playMatrix,f,t,order+1,player1);
                        }
                        else if (!abs(strcmp(player,player2))){
                            redoFunction(playMatrix,f,t,order+1,player2);
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
                            saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                        }
                        else if (f==11){
                            saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
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
                                else if(exitFlag[0]=='N' || exitFlag[0]=='n'){
                                    flagTest=1;
                                    flag9=0;
                                    break;
                                }
                            }

                        }
                    }

                    if (flag9==0){
                        flag9=1;
                        break;
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
                        flagTest=1;
                        break;
                    }
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flag9=0;
                            flagTest=0;
                            break;
                        }
                        undoScoreFlag=undoFunction(playMatrix,f,t,order,player1,player2);
                        flagTest=0;
                        flag9=0;
                        break;
                    }

                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flag9=0;
                            flagTest=0;
                            break;
                        }

                        if (!abs(strcmp(player,player1))){
                            redoFunction(playMatrix,f,t,order+1,player1);
                        }
                        else if (!abs(strcmp(player,player2))){
                            redoFunction(playMatrix,f,t,order+1,player2);
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
                            saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
                        }
                        else if (f==11){
                            saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,saveFlag,order);
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
                                else if(exitFlag[0]=='N' || exitFlag[0]=='n'){
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
                }
            }
            flag9=1;

        if ((x!=69 && y!=69 && z!=69 && l!=69) && (x!=66 && y!=66 && z!=66 && l!=66)){
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
                if (!(strcmp(player,player1))){
                    move1--;
                }
                else if (!(strcmp(player,player2))){
                    move2--;
                }
            }
            else if (undoScoreFlag==0){
                if (!(strcmp(player,player1))){
                    move2--;
                }
                else if (!(strcmp(player,player2))){
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
            if (!(strcmp(player,player1))){
                move1++;
            }
            else if (!(strcmp(player,player2))){
                move2++;
            }
            continue;
        }
        else if (x==67 && y==67 && z==67 && l==67){
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

        saveFunction2(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,0,order);
    }
    while (numberLines!=-1);

    system("cls");

    if (score1>score2){

        printf("Congratulations ");
        puts(player1);
        printf("\n Wins\n\n");
        winnerScore=score1;
        high_score(winnerScore,player1,highScore);
        saveHighscore(highScore);
    }
    else if (score2>score1){

        printf("Congratulations ");
        puts(player2);
        printf("\n Wins\n\n");
        winnerScore=score2;
        high_score(winnerScore,player2,highScore);
        saveHighscore(highScore);
    }
    else if (score1==score2){

        printf("Game Drawn!!");
    }

}
