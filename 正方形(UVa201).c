//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/5/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,m,t=0;
    int h[10][10],v[10][10];
    while(~scanf("%d%d",&n,&m))
    {  getchar();
        memset(h,0,sizeof(h));
        memset(v,0,sizeof(v));
        char c;
        int x,y;
        for(int i=0; i<m; i++)
        {
            scanf("%c%d%d",&c,&x,&y);
            getchar();
            if(c=='H')
                h[x][y]=1;
            else
                v[y][x]=1;
        }
        if(t++)
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",t);
        int sum=0;
        for(int l=1; l<=n; l++)
        { int con=0;
            for(int i=1; i+l<=n; i++)
                for(int j=1; j+l<=n; j++)
                {
                    int flag=1;
                    for(int k=j; k<j+l; k++)
                        if(!h[i][k]||!h[i+l][k])
                            flag=0;
                    for(int k=i; k<i+l; k++)
                        if(!v[k][j+l]||!v[k][j])
                            flag=0;
                            con+=flag;
                }
                if(con)
                    printf("%d square (s) of size %d\n",con,l);
                sum+=con;
        }
        if(!sum)
            printf("No completed squares can be found.\n");
    }
    return 0;
}
