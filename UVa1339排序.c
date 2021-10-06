//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/5/6.
//
//仅可输入小写字母
#include <stdio.h>
#include <string.h>
#define N 100
void paixu(int *c){int k;
    for(int i=25;i>=0;i--){
        for(int j=0;j<i;j++){
            if(c[j]>c[j+1]){k=c[j];c[j]=c[j+1];c[j+1]=k;}
        }
    }
}
int main(int argc, const char * argv[]) {
    char s1[N],s2[N],c;int count1=0,count2=0,c1[26]={0},c2[26]={0};
    while((c=getchar())!=EOF&&c!='\n'){s1[count1++]=c;}
    while((c=getchar())!=EOF&&c!='\n'){s2[count2++]=c;}
    if(count1!=count2){printf("NO");}
    else {
        for(int i=0;i<count1;i++){
            c1[s1[i]-'a']++;
            c2[s2[i]-'a']++;
        }
        paixu(c1);paixu(c2);int f=1;
        for(int i=0;i<26;i++){if(c1[i]!=c2[i]){f=0;break;}}
        if(f==1)printf("YES");
        else printf("NO");
    }
}
