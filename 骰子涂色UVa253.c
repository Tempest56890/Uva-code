//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/5/29.
//

#include <stdio.h>
#include <string.h>
char standard[6]={1,2,3,4,5,6};
int judge(char *a,char *b){
    for(int i=0;i<6;i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;
}
void turn_z(char *a){
    char k=a[1];
    a[1]=a[2];a[2]=a[4];a[4]=a[3];a[3]=k;
}
void turn_y(char *a){
    char k=a[0];
    a[0]=a[2];a[2]=a[5];a[5]=a[3];a[3]=k;
}
void turn_x(char *a){
    char k=a[0];
    a[0]=a[1];a[1]=a[5];a[5]=a[4];a[4]=k;
}
int main(int argc, const char * argv[]) {
    char a[6],b[6];int f=0;
    for(int i=0;i<6;i++){a[i]=getchar();}
    for(int i=0;i<6;i++){b[i]=getchar();}
    for(int i=0;i<4&&!f;i++){
        turn_z(a);
        for(int j=0;j<4&&!f;j++){
            turn_y(a);
            for(int z=0;z<4;z++){
                turn_x(a);
                if(judge(a,b)){
                    f=1;
                    printf("True");
                    break;
                }
            }
        }
    }
    if(!f)printf("False");
}
