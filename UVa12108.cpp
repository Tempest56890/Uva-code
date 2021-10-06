//
//  main.cpp
//  1
//
//  Created by 韩韩骐骏 on 2021/10/4.
/*
 该程序用二维整数数组记录状态，学生初始状态为Ai-Ci+1，并在区间[-Bi+1，Ai]间累次减1，大于0时表
 示清醒，否则表示睡眠；每当学生状态为-Bi+1，下一次将回到Ai；临睡前检查到睡觉人数小于等于清醒人数
 后状态将从1返回到Ai；当学生处于睡眠状态并在下一刻将要继续睡眠时不会检查全班睡觉人数是否大于清醒
 人数，因此“是否检查”这个功能用状态大于或者小于等于0来区分，而不需要再开一个数组。
 
 可以证明的是，若在某个时刻出现全班睡觉人数小于等于清醒人数的状态，则这个时刻以后将不会再出现睡觉
 的人数大于清醒人数的状态，从而清醒的人将一直清醒下去，睡觉人数逐渐递减至零，程序输出time而非-1.

 由于有可能不存在“全部都清醒”的时刻，故用整数区间描述状态(相较于只用0和1来描述)的另一个好处就显现
 出来了，即每次将该时刻下各学生的状态与初始状态比较，若完全一致则表明处于结束不了的循环中，则直接
 输出-1并结束整个程序。
 */

#include <iostream>
#include <cstring>
using namespace std;
const int N=100;
int state[N][1000];

int judgewake(int time,int n,int (*stu)[3]){
    //检查全班睡觉人数是否严格大于清醒人数,并且由于在moveon()中被调用，应先进行声明或定义
    if(!time)return 1;
    else {
        int m=0;
        for(int j=0;j<n;j++){
            if(state[j][time-1]<=0)m++;
        }
        if(m>=n/2+1)return 1;
    }
    return 0;
}

void moveon(int time,int n,int (*stu)[3]){
    if(!time){
        for(int i=0;i<n;i++){
            state[i][0]=stu[i][0]-stu[i][2]+1;
        }
    }
    else {
        for(int i=0;i<n;i++){
            if(state[i][time-1]==-stu[i][1]+1)state[i][time]=stu[i][0];
            else if(state[i][time-1]==1&&!judgewake(time,n,stu))state[i][time]=stu[i][0];
            else state[i][time]=state[i][time-1]-1;
        }
    }
}

int judgeback(int time,int n,int (*stu)[3]){
    //判断是否状态循环了
    int sum=0;
    for(int i=0;i<n;i++){
        if(state[i][time]==state[i][0])sum++;
    }
    if(sum==n&&time>0)return 1;
    return 0;
}

int judgesleep(int time,int n,int (*stu)[3]){
    //如果状态不会循环，判断是否全部清醒
    int sum=0;
    for(int i=0;i<n;i++){
        if(state[i][time]>0)sum++;
    }
    if(sum==n)return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n&&n){
        int stu[n][3],time=0;
        for(int i=0;i<n;i++)cin>>stu[i][0]>>stu[i][1]>>stu[i][2];
        memset(state,0,sizeof(state));
        moveon(time,n,stu);
        while(!judgeback(time,n,stu)&&judgewake(time,n,stu)){
            time++;
            moveon(time,n,stu);
        }
        if(!judgewake(time,n,stu)){
            while(!judgesleep(time,n,stu)){
                time++;
                moveon(time,n,stu);
            }
            cout<<time+1<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}

/*
 看到某位同学的代码，简单但巧妙地用了一下Floyd判环算法，即用两个数组描述各同学
 的状态，不过一个每次走一步，另一个每次走两步。这样来判断无解很不错。（另外，我
 感觉自己好多代码好多余啊，醉了）
*/
