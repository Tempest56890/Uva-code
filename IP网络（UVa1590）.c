//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/9/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
void change(int ip[1005][32],int p,int q,int n,int j)
{
    int t = 0,i;
    int a[8];
    memset(a,0,sizeof(a));
     while(n)
     {
         int x = n%2;
         a[t++] = x;
         n/=2;
     }
     for(i=p; i<q; i++)
         ip[j][i] = a[7-i+p];
 }
 int main()
 {
     int ip[1005][32];
     int a,b,c,d,i,j,t;
     char s[50];
     while(scanf("%d",&t)!=EOF)
     {
         memset(ip,0,sizeof(ip));
         getchar();
         for(i=0; i<t; i++)
         {
             gets(s);
             if(sscanf(s,"%d.%d.%d.%d",&a,&b,&c,&d)==4)
             {
                 change(ip,0,8,a,i);
                 change(ip,8,16,b,i);
                 change(ip,16,24,c,i);
                 change(ip,24,32,d,i);
             }
         }
         int x = 32;
         for(j=0; j<32; j++)
         {
             int flag = 1;
             for(i=1; i<t; i++)
             {
                 if(ip[i][j]!=ip[i-1][j])
                 {
                     flag = 0;
                     break;
                 }
             }
             if(!flag)
             {
                 x=j;
                 break;
             }
         }
         int q=0,w=0,e=0,r=0;
         int q1=0,w1=0,e1=0,r1=0;
         for(i=0; i<x; i++)
         {
             if(i<8)
             {
                 q+=ip[0][i]*(int)pow(2,7-i);
                 q1 += (int)pow(2,7-i);
             }
            else if(i>=8&&i<16)
             {
                 w+=ip[0][i]*(int)pow(2,15-i);
                 w1 += (int)pow(2,15-i);
             }
             else if(i>=16&&i<24)
             {
                 e+=ip[0][i]*(int)pow(2,23-i);
                 e1 += (int)pow(2,23-i);
             }
             else
             {
                 r+=ip[0][i]*(int)pow(2,31-i);
                 r1 += (int)pow(2,31-i);
             }
         }
         printf("%d.%d.%d.%d\n",q,w,e,r);
         printf("%d.%d.%d.%d\n",q1,w1,e1,r1);

     }
     return 0;
 }
