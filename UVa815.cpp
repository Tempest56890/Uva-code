//
//  main.cpp
//  1
//
//  Created by 韩韩骐骏 on 2021/10/6.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int high[1000];

int main(int argc, const char * argv[]) {
    int m,n,i=0,j=0,all;double h;
    while(cin>>m>>n&&m&&n){
        for(;i<m*n;i++)cin>>high[i];
        cin>>all;
        h=all/100.0;
        while(j<m*n){
            h+=high[j];
            if(j*high[j+1]>h)
                break;
            j++;
        }
        cout<<setprecision(4)<<(h/j)<<endl<<(j+1)*100.0/(m*n)<<"%"<<endl;
    }
    return 0;
}

//这道题主要是为了试试setprecision。。。
