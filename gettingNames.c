#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>


void playerNames (char player1[17], char player2[17]){

    int numberLines,x,y,z,l,v,tm,ts,tm1,ts1,tm2,ts2,th,th2,th1,move1=0,move2=0,yy1,yy2,yy=0,xy1=0,xy2=0,chTest=0,spaceflag1=0,spaceflag2=0;
    int x11,y11,z11,l11,xx=0,yyy=0,zz=0,ll=0,x1x,y1y,z1z,l1l,i,j;

    printf("Enter Player 1 Name (Max 15): ");

    while ((yy1=getchar()) != '\n'){
        if(yy<16){
            player1[yy]=yy1;
            yy++;
        }
    }
    player1[yy]='\0';

    for(i=0;i<17;i++){
        if(player1[i]==' ' || player1[i]=='\t'){
            spaceflag1=1;
        }
    }

    while (player1[0]=='\0' || player1[0]=='0' || player1[15] != '\0' || spaceflag1==1 ){

        printf("UnAccepted Name\n");
        yy=0;
        spaceflag1=0;
        for(i=0;i<17;i++){
            player1[i]='\0';
        }
        printf("Enter Player 1 Name (Max 15): ");

        while ((yy1=getchar()) != '\n'){
            if(yy<16){
                player1[yy]=yy1;
                yy++;
            }
        }
        player1[yy]='\0';
        for(i=0;i<17;i++){
            if(player1[i]==' '|| player1[i]=='\t'){
                spaceflag1=1;
            }
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
    }
    player2[yy]='\0';

    for(i=0;i<17;i++){
        if(player2[i]==' '|| player2[i]=='\t'){
            spaceflag2=1;
        }
    }


    while(player2[0]=='\0' || player2[0]=='0' || player2[15] != '\0' || spaceflag2==1 || strcmp(player1,player2)==0){

        printf("UnAccepted Name\n");
        yy=0;
        spaceflag2=0;
        for(i=0;i<17;i++){
            player2[i]='\0';
        }
        printf("Enter Player 2 Name (Max 15): ");

        while ((yy2=getchar()) != '\n'){
            if(yy<16){
                player2[yy]=yy2;
                yy++;
            }
        }
        player2[yy]='\0';
        for(i=0;i<17;i++){
            if(player2[i]==' '|| player2[i]=='\t'){
                spaceflag2=1;
            }
        }
    }

}

void playerNamesComputer (char player1[17], char player2[17]){

    int numberLines,x,y,z,l,v,tm,ts,tm1,ts1,tm2,ts2,th,th2,th1,move1=0,move2=0,yy1,yy2,yy=0,xy1=0,xy2=0,chTest=0,spaceflag=0;
    int x11,y11,z11,l11,xx=0,yyy=0,zz=0,ll=0,x1x,y1y,z1z,l1l,i,j;

    strcpy(player2,"Computer");


    printf("Enter Your Name (Max 15): ");

    while ((yy1=getchar()) != '\n'){
        if(yy<16){
            player1[yy]=yy1;
            yy++;
        }
    }
    player1[yy]='\0';

    for(i=0;i<17;i++){
        if(player1[i]==' '|| player1[i]=='\t'){
            spaceflag=1;
        }
    }



    while(player1[0]=='\0' || player1[0]=='0' || player1[15] != '\0' || spaceflag==1 || strcmp(player1,player2)==0 ){

        printf("Un Accepted Name\n");
        yy=0;
        spaceflag=0;
        for(i=0;i<17;i++){
            player1[i]='\0';
        }

        printf("Enter Your Name (Max 15): ");
        while ((yy1=getchar()) != '\n'){
            if(yy<16){
                player1[yy]=yy1;
                yy++;
            }
        }
        player1[yy]='\0';
        for(i=0;i<17;i++){
            if(player1[i]==' '|| player1[i]=='\t'){
                spaceflag=1;
            }
        }
    }
}
