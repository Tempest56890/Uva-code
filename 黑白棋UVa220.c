//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/5/25.
//

#include <stdio.h>
#include <string.h>
int qi[8][8];
int judge(int m,int n){
    int k=qi[m][n];int i;
    if(m>=2&&n>=2&&qi[m-1][n-1]==-k){
        for(i=2;m-i>=0&&n-i>=0;i++){
            if(qi[m-i][n-i]==0)break;
            else if(qi[m-i][n-i]==k)return 1;
        }
    }
    if(m>=2&&qi[m-1][n]==-k){
        for(i=2;m-i>=0;i++){
            if(qi[m-i][n]==0)break;
            else if(qi[m-i][n]==k)return 1;
        }
    }
    if(m>=2&&n<6&&qi[m-1][n+1]==-k){
        for(i=2;m-i>=0&&n+i<6;i++){
            if(qi[m-i][n+i]==0)break;
            else if(qi[m-i][n+i]==k)return 1;
        }
    }
    if(n<6&&qi[m][n+1]==-k){
        for(i=2;n+i<6;i++){
            if(qi[m][n+i]==0)break;
            else if(qi[m][n+i]==k)return 1;
        }
    }
    if(m<6&&qi[m+1][n]==-k){
        for(i=2;m+i<6;i++){
            if(qi[m+i][n]==0)break;
            else if(qi[m+i][n]==k)return 1;
        }
    }
    if(m<6&&n<6&&qi[m+1][n+1]==-k){
        for(i=2;m+i<6&&n+i<6;i++){
            if(qi[m+i][n+i]==0)break;
            else if(qi[m+i][n+i]==k)return 1;
        }
    }
    if(m<6&&n>=2&&qi[m+1][n-1]==-k){
        for(i=2;m+i<6&&n-i>=0;i++){
            if(qi[m+i][n-i]==0)break;
            else if(qi[m+i][n-i]==k)return 1;
        }
    }
    if(n>=2&&qi[m][n-1]==-k){
        for(i=2;n-i>=0;i++){
            if(qi[m][n-i]==0)break;
            else if(qi[m][n-i]==k)return 1;
        }
    }
    return 0;
}
void Mrc(int player){
    int r,c;
    scanf("%d%d",&r,&c);
    qi[r][c]=player;
    for(int i=1;r-i>=0;i++){
        if(qi[r-i][c]==-player){qi[r-i][c]=player;}
        else break;
    }
    for(int i=1;r+i<8;i++){
        if(qi[r+i][c]==-player){qi[r+i][c]=player;}
        else break;
    }
    for(int i=1;c-i>=0;i++){
        if(qi[r][c-i]==-player){qi[r][c-i]=player;}
        else break;
    }
    for(int i=1;c+i>=0;i++){
        if(qi[r][c+i]==-player){qi[r][c+i]=player;}
        else break;
    }
    for(int i=1;r-i>=0&&c-i>=0;i++){
        if(qi[r-i][c-i]==-player){qi[r-i][c-i]=player;}
        else break;
    }
    for(int i=1;r-i>=0&&c+i<8;i++){
        if(qi[r-i][c+i]==-player){qi[r-i][c+i]=player;}
        else break;
    }
    for(int i=1;r+i<8&&c-i>=0;i++){
        if(qi[r+i][c-i]==-player){qi[r+i][c-i]=player;}
        else break;
    }
    for(int i=1;r+i<8&&c+i<8;i++){
        if(qi[r+i][c+i]==-player){qi[r=i][c+i]=player;}
        else break;
    }
}
int gamejudge(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            if(qi[i][j]==0){
                return 1;
            }
    }
    return 0;
}
void printsystem(){
    printf("--------------------\n");
    printf("  1  2  3  4  5  6  7  8 \n");
    for(int i=0;i<8;i++){
        printf("\n%d",i+1);
        for(int j=0;j<8;j++){
            switch(qi[i][j]){
                case 0:printf("   ");break;
                case 1:printf(" * ");break;
                case -1:printf(" o ");break;
            }
        }
        printf("\n");
    }
    printf("--------------------\n");
}
int main(){
    memset(qi,0,sizeof(qi));
    char command;int player=1;int sumb=0,sumw=0;int sum=0;int x0,y0,z0;
    printf("You need to put some basic qi.\n");
    while(scanf("%d%d%d",&x0,&y0,&z0)==3&&x0&&y0&&z0){
        qi[x0][y0]=z0;
    }
    getchar();
    printsystem();
    while((command=getchar())!=EOF&&gamejudge()){
        sum=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(judge(i,j))sum++;
            }
        }
        if(sum){
            printf("No legal mmove!\n");
            continue;
        }
        if(command=='Q'){
            printf("You have quit.\n");
            break;
        }
        else if(command=='L'){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(judge(i,j))printf("(%d,%d)\n",i,j);
                }
            }
        }
        else if(command=='M'){
            Mrc(player);
            player=-player;
            getchar();
        }
        else printf("What the hell are you talking about?\n");
        player=-player;
        printsystem();
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(qi[i][j]==1)sumb++;
            else if(qi[i][j]==-1)sumw++;
        }
    }
    if(sumb<sumw)printf("White wins.\n");
    else if(sumb>sumw)printf("Black wins.\n");
    else printf("Peace!\n");
}
