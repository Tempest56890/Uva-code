//
//  main.c
//  1
//
//  Created by 韩韩骐骏 on 2021/5/11.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXN 50
#define MAXN2 10
#define MAXN3 10000
int grid[MAXN+1][MAXN+1];
enum operation {EX, DC, DR, IC, IR};
struct {
    int cmd;
    int a, x[MAXN2+1];
} cmd[MAXN3];
int ccount;
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
void getax(int index)
{
    int i;
    scanf("%d", &cmd[index].a);
    for(i=0; i<cmd[index].a; i++)
        scanf("%d", &cmd[index].x[i]);
    qsort(cmd[index].x, cmd[index].a, sizeof(cmd[index].x[0]), cmp);
}
void simulate(int row, int col)
{
    int row1, col1, row2, col2, i, j;
    row1 = row2 = row;
    col1 = col2 = col;
    for(i=0; i<ccount; i++) {
        switch(cmd[i].cmd) {
        case EX:
            if(row2 == cmd[i].x[0] && col2 == cmd[i].x[1]) {
                row1 = row2 = cmd[i].x[2];
                col1 = col2 = cmd[i].x[3];
            } else if(row2 == cmd[i].x[2] && col2 == cmd[i].x[3]) {
                row1 = row2 = cmd[i].x[0];
                col1 = col2 = cmd[i].x[1];
            }
            break;
        case DR:
            for(j=0; j<cmd[i].a; j++) {
                if(cmd[i].x[j] == row1) {
                    printf("Cell data in (%d,%d) GONE\n", row, col);
                    return;
                } else if(cmd[i].x[j] < row1) {
                    row2--;
                } else
                    break;
            }
            row1 = row2;
            break;
        case DC:
            for(j=0; j<cmd[i].a; j++) {
                if(cmd[i].x[j] == col1) {
                    printf("Cell data in (%d,%d) GONE\n", row, col);
                    return;
                } else if(cmd[i].x[j] < col1) {
                    col2--;
                } else
                    break;
            }
            col1 = col2;
            break;
        case IR:
            for(j=0; j<cmd[i].a; j++) {
                if(cmd[i].x[j] <= row1) {
                    row2++;
                } else
                    break;
            }
            row1 = row2;
            break;
        case IC:
            for(j=0; j<cmd[i].a; j++) {
                if(cmd[i].x[j] <= col1) {
                    col2++;
                } else
                    break;
            }
            col1 = col2;
            break;
        }
    }
    printf("Cell data in (%d,%d) moved to (%d,%d)\n", row, col, row2, col2);
}
int main(void){
    int caseno, r, c, n, i;
    char command[8];
    int cn, row, col;
    caseno = 0;
    while(scanf("%d%d", &r, &c) != EOF) {
        if(r == 0 && c == 0)
            break;
        /* 读入命令，存储在结构数组cmd[]中 */
        ccount = 0;
        scanf("%d", &n);
        for(i=1; i<=n; i++) {
            scanf("%s", command);
            if(command[0] == 'E') {
                /* 单元内容交换命令 */
                cmd[ccount].cmd = EX;
                scanf("%d%d%d%d", &cmd[ccount].x[0], &cmd[ccount].x[1], &cmd[ccount].x[2], &cmd[ccount].x[3]);
                ccount++;
            } else if(command[0] == 'D') {
                cmd[ccount].cmd = (command[1] == 'C') ? DC : DR;
                getax(ccount);
                ccount++;
            } else if(command[0] == 'I') {
                cmd[ccount].cmd = (command[1] == 'C') ? IC : IR;
                getax(ccount);
                ccount++;
            }
        }
        if(caseno)
            printf("\n");
        printf("Spreadsheet #%d\n", ++caseno);
        /* 读入单元坐标进行模拟 */
        scanf("%d", &cn);
        for(i=1; i<=cn; i++) {
            scanf("%d%d", &row, &col);
            simulate(row, col);
        }
    }
    return 0;
}
