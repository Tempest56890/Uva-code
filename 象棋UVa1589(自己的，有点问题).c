//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/5/11.
//

#include <stdio.h>
char a[10][9];
int judgeR(int x0,int y0){int i;
    if(y0>=2&&a[x0][y0-1]=='o'){
        i=y0-2;
        while(i>=0){if(a[x0][i]!='o')break;i--;}
        if(i>=0&&a[x0][i]=='R')return 1;
    }
    if(y0<=6&&a[x0][y0+1]=='o'){
        i=y0+2;
        while(i<=8){if(a[x0][i]!='o')break;i++;}
        if(i<=8&&a[x0][i]=='R')return 1;
    }
    if(x0>=2&&a[x0-1][y0]=='o'){
        i=x0-2;
        while(i>=0){if(a[i][y0]!='o')break;i--;}
        if(i>=0&&a[i][y0]=='R')return 1;
    }
    if(x0<=7&&a[x0+1][y0]=='o'){
        i=y0+2;
        while(i<=9){if(a[i][y0]!='o')break;i--;}
        if(i<=9&&a[i][y0]=='R')return 1;
    }
    return 0;
}
int judgeH(int x0,int y0){
    if(x0-1>=0&&y0-1>=0&&a[x0-1][y0-1]=='o'){
        if(x0-2>=0&&a[x0-2][y0-1]=='H')return 1;
        if(y0-2>=0&&a[x0-1][y0-2]=='H')return 1;
    }
    if(x0-1>=0&&y0+1<=8&&a[x0-1][y0+1]=='o'){
        if(x0-2>=0&&a[x0-2][y0+1]=='H')return 1;
        if(y0+2<=8&&a[x0-1][y0+2]=='H')return 1;
    }
    if(x0+1<=9&&y0-1>=0&&a[x0+1][y0-1]=='o'){
        if(x0+2<=9&&a[x0+2][y0-1]=='H')return 1;
        if(y0-2>=0&&a[x0+1][y0-2]=='H')return 1;
    }
    if(x0+1<=9&&y0+1<=8&&a[x0+1][y0+1]=='o'){
        if(x0+2<=9&&a[x0+2][y0+1]=='H')return 1;
        if(y0+2<=8&&a[x0+1][y0+2]=='H')return 1;
    }
    return 0;
}
int judgeC(int x0,int y0){
    if(x0-1>=0&&y0-1>=0&&a[x0-1][y0-1]=='o'){
        if(y0-2>=0&&a[x0-1][y0-2]=='H')return 1;
        if(x0-2>=0&&a[x0-2][y0-1]=='H')return 1;
    }
    if(x0+1<=9&&y0-1>=0&&a[x0+1][y0-1]=='o'){
        if(x0+2<=9&&a[x0+2][y0-1]=='H')return 1;
        if(y0-2>=0&&a[x0+1][y0-2]=='H')return 1;
    }
    if(x0-1>=0&&y0+1<=8&&a[x0-1][y0+1]=='o'){
        if(x0-2>=0&&a[x0-2][y0+1]=='H')return 1;
        if(y0+2<=8&&a[x0-1][y0+2]=='H')return 1;
    }
    if(x0+1<=9&&y0+1<=8&&a[x0+1][y0+1]=='o'){
        if(x0+2<=9&&a[x0+2][y0+1]=='H')return 1;
        if(y0+2<=8&&a[x0+1][y0+2]=='H')return 1;
    }
    return 0;
}
int judgeG(int x0,int y0){
    if(y0-2>=0&&a[x0][y0-2]=='G')return 1;
    else if(y0+2<=8&&a[x0][y0+2]=='G')return 1;
    else if(x0-2>=0&&a[x0-2][y0]=='G')return 1;
    else if(x0+2<=9&&a[x0+2][y0]=='G')return 1;
    else if(x0-1>=0&&y0-1>=0&&a[x0-1][y0-1]=='G')return 1;
    else if(x0+1<=9&&y0-1>=0&&a[x0+1][y0-1]=='G')return 1;
    else if(x0-1>=0&&y0+1>=0&&a[x0-1][y0+1]=='G')return 1;
    else if(x0+1>=0&&y0+1>=0&&a[x0+1][y0+1]=='G')return 1;
    return 0;
}
int main(int argc, const char * argv[]) {
    int n,x0,y0,x,y;char role;
    while((scanf("%d %d %d",&n,&x0,&y0))==3&&n){
        for(int i=0;i<10;i++){for(int j=0;j<9;j++){a[i][j]=' ';}}
        a[--x0][--y0]='M';
        while(n--){
            scanf("%c %d %d",&role,&x,&y);
            a[x-1][y-10]=role;
        }
    if(judgeR(x0-1,y0)||judgeR(x0,y0-1)||judgeR(x0+1,y0)||judgeR(x0,y0+1))printf("Yes");
    else if(judgeH(x0-1,y0)||judgeH(x0,y0-1)||judgeH(x0+1,y0)||judgeH(x0,y0+1))printf("Yes");
    else if(judgeC(x0-1,y0)||judgeC(x0,y0-1)||judgeC(x0+1,y0)||judgeC(x0,y0+1))printf("Yes");
    else if(judgeG(x0,y0))printf("Yes");
    else printf("No");
    }
}
