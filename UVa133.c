//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/5/11.
//
#include<stdio.h>
int Sum(int *a,int n){
    int s=0;
    for(int i=0;i<n;i++){s+=a[i];}
    if(s!=0)return 1;
    else return 0;
}
int main() {
    int n,k,m;
    while(scanf("%d %d %d",&n,&k,&m)==3&&n!=0){
        int a[n];int i=-1,j=n;
        for(int t=0;t<n;t++){a[t]=1;}
        while(Sum(a,n)){
            int count1=0,count2=0;
            while(count1<k){i=(i+1)%n;if(a[i]){count1++;}}
            while(count2<m){j=(n+j-1)%n;if(a[j]){count2++;}}
            if(a[i]){printf("%d ",i+1);a[i]=0;}
            if(a[j]){printf("%d ",j+1);a[j]=0;}
        }printf("\n");
    }
}
