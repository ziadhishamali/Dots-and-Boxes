void playFunctionComputer (char gameDifficulty[], char mainMenu[], int loadFlag, int modeFlag){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &ConsoleInfo);
    int originalAttrs = ConsoleInfo.wAttributes;

    int vs=1;

    int score1=0,score2=0,turn=0,winnerScore;
    int mode;
    char player[16],player2[16],player1[16],pl,x1[2],y1[2],z1[2],l1[2];
    int numberLines,v,tm,ts,tm1,ts1,tm2,ts2,limit1,move1=0,move2=0,ai=0,totalScore=0,yy1,yy2,yy=0,xy1=0,xy2=0,chTest=0;
    int n,m,i,j,k,f,t,h,g,q,r=1,q1,r1,x,y,z,l;
    highScoreStruct highScore[10];
    play playMatrix[11][11];

    loadHighscore(highScore);


    int flagger=1;
    int order=0,lineCounter=0;


    for(i=0;i<2;i++){
        x1[i]='\0';
    }
    for(i=0;i<2;i++){
        y1[i]='\0';
    }
    for(i=0;i<2;i++){
        z1[i]='\0';
    }
    for(i=0;i<2;i++){
        l1[i]='\0';
    }





    for(i=0;i<16;i++){
        player1[i]='\0';
    }
    for(i=0;i<16;i++){
        player2[i]='\0';
    }

    if (loadFlag==0){

        strcpy(player2,"Computer");

        printf("Enter Your Name (Max 15): ");

        while ((yy1=getchar()) != '\n'){
            if(yy<15){
                player1[yy]=yy1;
                yy++;
            }
            player1[yy]='\0';
        }

        while(player1[0] == ' ' || player1[0] == '\0' || player1[0] == '0'){

            printf("Un Accepted Name\n");
            yy=0;
            printf("Enter Your Name (Max 15): ");

            while ((yy1=getchar()) != '\n'){
                if(yy<15){
                    player1[yy]=yy1;
                    yy++;
                }
                player1[yy]='\0';
            }
        }

        while(player1[14] != '\0'){
            if(xy1==1){
                break;
            }
            printf("Un Accepted Name\n");
            yy=0;
            printf("Enter Your Name (Max 15): ");

            while ((yy1=getchar()) != '\n'){
                if(yy<15){
                    player1[yy]=yy1;
                    yy++;
                }
                player1[yy]='\0';
            }

                if(yy<15){
                    xy1=1;
                }

        }

        while(player1[0] == ' ' || player1[0] == '\0' || player1[0] == '0'){

            printf("Un Accepted Name\n");
            yy=0;
            printf("Enter Your Name (Max 15): ");

            while ((yy1=getchar()) != '\n'){
                if(yy<15){
                    player1[yy]=yy1;
                    yy++;
                }
                player1[yy]='\0';
            }
        }

        system("cls");

        tm1= clock()/CLOCKS_PER_SEC/60;
        ts1= clock()/CLOCKS_PER_SEC%60;

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

        char pl3[16];

        tm1= clock()/CLOCKS_PER_SEC/60;
        ts1= clock()/CLOCKS_PER_SEC%60;

        if (modeFlag==5){
            f=t=5;
            n=m=4;
            limit1=4;
            loadFunction2(f,vs,playMatrix,player1,player2,pl3,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order);
            lineCounter=12;
            turn=2;

        }


        else if (modeFlag==11){
            f=t=11;
            n=m=7;
            limit1=7;
            loadFunction1(f,vs,playMatrix,player1,player2,pl3,&tm,&ts,&move1,&move2,&numberLines,&turn,&totalScore,loadFlag,&order);
            lineCounter=60;
            turn=2;
        }
    }

/* ************************************************************************************************** */

    srand ( time(NULL) );

    int undoFlag=0;
    int undoFlag2=0;
    int undoFlag3=0,undoFlag4=0,undoFlag5=0;
    int computerPlay_counter=0;
    int sc1=0;
    int sc2=0;
    int flag1=0;
    int flag2=0;
    int load,saveFlag;

    do {
        sc1=0;
        sc2=0;
        flag1=score1;
        flag2=score2;

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


        int temp;

        if (numberLines==0){
            break;
        }//playFunction(gameDifficulty,mainMenu,load,modeFlag);

/* ********************************************************************************************* */

        /* Player 1 turn*/
        int testFlag=0;
        int undoScoreFlag=0,flag9=1,totalScore;
        int redoScoreFlag=0;
        char exitFlag[2];

        if (!abs(strcmp(player,player1))){


            printf("Choose a Line:");
            scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
            testFlag=testPoints(x1,y1,z1,l1);
            int flagTest=1;
            int i;
            x=x1-48;
            y=y1-48;
            z=z1-48;
            l=l1-48;

            while (flagTest){
                flagTest=0;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            break;
                        }

                        if (undoFlag4==1){
                            order=0;
                        }

                        order++;
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        while (redoScoreFlag==1){
                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            turn=1;
                        }
                        if (redoScoreFlag==0){
                            order++;
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            while (redoScoreFlag==1){
                                order++;
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') && (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
                        break;
                    }
                while (testFlag==0){
                    printf("(Error!) Enter a Digit\n\n");
                    scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                    testFlag=testPoints(x1,y1,z1,l1);
                }
                x=x1-48;
                y=y1-48;
                z=z1-48;
                l=l1-48;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            order--;
                            break;
                        }
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        order++;
                        while (redoScoreFlag==1){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            order++;
                        }
                        if (redoScoreFlag==0){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            order++;
                            while (redoScoreFlag==1){
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                order++;
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') || (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
                        break;
                    }

                while (x>(n-1) || x<1 || y>(n-1) || y<1 || z>(n-1) || z<1 || l>(n-1) || l<1){
                    printf("(Error!) Points Not Valid\n\n");
                    printf("Choose a Line:\n");
                    scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                    testFlag=testPoints(x1,y1,z1,l1);
                    x=x1-48;
                    y=y1-48;
                    z=z1-48;
                    l=l1-48;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            order--;
                            break;
                        }
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        order++;
                        while (redoScoreFlag==1){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            order++;
                        }
                        if (redoScoreFlag==0){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            order++;
                            while (redoScoreFlag==1){
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                order++;
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') || (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
                        break;
                    }
                    while (testFlag==0){
                        printf("(Error!) Enter a Digit\n\n");
                        scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                        testFlag=testPoints(x1,y1,z1,l1);
                    }
                    x=x1-48;
                    y=y1-48;
                    z=z1-48;
                    l=l1-48;
                    flagTest=1;
                }

                while (x!=z && y!=l){
                    printf("(Error!) Don't Choose diagonal points\n\n");
                    printf("Choose a Line:\n");
                    scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                    testFlag=testPoints(x1,y1,z1,l1);
                    flagTest=1;
                    x=x1-48;
                    y=y1-48;
                    z=z1-48;
                    l=l1-48;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            order--;
                            flagTest=0;
                            break;
                        }
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        order++;
                        while (redoScoreFlag==1){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            order++;
                        }
                        if (redoScoreFlag==0){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            order++;
                            while (redoScoreFlag==1){
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                order++;
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') || (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
                        break;
                    }
                    while (testFlag==0){
                        printf("(Error!) Enter a Digit\n\n");
                        scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                        testFlag=testPoints(x1,y1,z1,l1);
                    }
                    x=x1-48;
                    y=y1-48;
                    z=z1-48;
                    l=l1-48;
                    flagTest=1;
                }


                while (x==z && y==l){
                    printf("(Error!) Don't Choose The Same Point\n\n");
                    printf("Choose a Line:\n");
                    scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                    testFlag=testPoints(x1,y1,z1,l1);
                    flagTest=1;
                    x=x1-48;
                    y=y1-48;
                    z=z1-48;
                    l=l1-48;
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            order--;
                            break;
                        }
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        order++;
                        while (redoScoreFlag==1){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            order++;
                        }
                        if (redoScoreFlag==0){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            order++;
                            while (redoScoreFlag==1){
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                order++;
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') || (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
                        break;
                    }
                    while (testFlag==0){
                        printf("(Error!) Enter a Digit\n\n");
                        scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                        testFlag=testPoints(x1,y1,z1,l1);
                    }
                    x=x1-48;
                    y=y1-48;
                    z=z1-48;
                    l=l1-48;
                }

                while (abs(x-z)>1 || abs(y-l)>1){
                    printf("(Error!) Choose Two Adjacent points\n\n");
                    printf("Choose a Line:\n");
                    scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                    testFlag=testPoints(x1,y1,z1,l1);
                    while (testFlag==0){
                        printf("(Error!) Enter a Digit\n\n");
                        scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                        testFlag=testPoints(x1,y1,z1,l1);
                    }
                    x=x1-48;
                    y=y1-48;
                    z=z1-48;
                    l=l1-48;
                    flagTest=1;
                }
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            order--;
                            break;
                        }
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        order++;
                        while (redoScoreFlag==1){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            order++;
                        }
                        if (redoScoreFlag==0){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            order++;
                            while (redoScoreFlag==1){
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                order++;
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') || (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
                        break;
                    }

                if (x==z){

                    if (l<y){
                        temp=y;
                        y=l;
                        l=temp;
                    }

                    while (playMatrix[2*(x-1)][2*(l-1)-1].line==1){
                        printf("(Error!) The Line is Played\n\n");
                        printf("Choose a Line:\n");
                        scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                        testFlag=testPoints(x1,y1,z1,l1);
                        while (testFlag==0){
                            printf("(Error!) Enter a Digit\n\n");
                            scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                            testFlag=testPoints(x1,y1,z1,l1);
                        }
                        flagTest=1;
                        x=x1-48;
                        y=y1-48;
                        z=z1-48;
                        l=l1-48;
                        break;
                    }
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            order--;
                            break;
                        }
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        order++;
                        while (redoScoreFlag==1){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            order++;
                        }
                        if (redoScoreFlag==0){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            order++;
                            while (redoScoreFlag==1){
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                order++;
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') || (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
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
                        scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                        testFlag=testPoints(x1,y1,z1,l1);
                        flagTest=1;
                        while (testFlag==0){
                            printf("(Error!) Enter a Digit\n\n");
                            scanf(" %c %c %c %c",&x1,&y1,&z1,&l1);
                            testFlag=testPoints(x1,y1,z1,l1);
                            flagTest=1;
                        }
                        x=x1-48;
                        y=y1-48;
                        z=z1-48;
                        l=l1-48;
                        break;
                    }
                    if (x==69 && y==69 && z==69 && l==69){
                        if (numberLines==lineCounter){
                            flagTest=0;
                            break;
                        }
                        undoFunctionComputer(playMatrix,f,t,&order,&move1,&move2,&turn,&numberLines,player1,player2);

                        flagTest=0;
                        flag9=0;
                        break;
                    }
                    if (flag9==0){
                        break;
                    }
                    else if (x==66 && y==66 && z==66 && l==66){
                        if (!undoFlag){
                            flagTest=0;
                            order--;
                            break;
                        }
                        redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                        order++;
                        while (redoScoreFlag==1){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move1,&turn,&numberLines,player1);
                            order++;
                        }
                        if (redoScoreFlag==0){
                            redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                            order++;
                            while (redoScoreFlag==1){
                                redoScoreFlag=redoFunctionComputer(playMatrix,f,t,&order,&move2,&turn,&numberLines,player2);
                                order++;
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
                        scanf(" %d",&saveFlag);
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
                        gets(exitFlag);
                        while ((exitFlag[0]!= 'N' && exitFlag[0]!= 'Y') && (exitFlag[0]!= 'n' && exitFlag[0]!= 'y')){
                            printf("Choose Y or N ");
                            gets(exitFlag);
                        }
                        if (exitFlag[0]=='Y'||exitFlag[0]=='y'){
                            return 0;
                        }
                    }
                    else{undoFlag=0;}
                    if (flag9==0){
                        break;
                    }
                }


            }
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
            if ((x!=69 && y!=69 && z!=69 && l!=69) && (x!=66 && y!=66 && z!=66 && l!=66)){
                for (i=0;i<f;i++){
                    for (j=0;j<t;j++){
                        if (playMatrix[i][j].order==order+1){
                            playMatrix[i][j].order=0;
                        }
                    }
                }
            }

        if (x==69 && y==69 && z==69 && l==69){
            undoFlag++;
            undoFlag3=0;
            if (numberLines==lineCounter){
                undoFlag4=1;
                undoFlag5=0;
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

        saveFunction1(f,vs,playMatrix,player1,player2,player,tm,ts,move1,move2,numberLines,turn,totalScore,0,order);
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
