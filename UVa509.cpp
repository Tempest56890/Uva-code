//
//  main.cpp
//  1
//
//  Created by 韩韩骐骏 on 2021/9/26.
//

#include <iostream>
#include <string>
using namespace std;
char datadisk[100][110];
void getData(int d){
    memset(datadisk,0,sizeof(datadisk));
    for(int i=0;i<d;i++){
        cin>>datadisk[i];
    }
}

int compare(int X,int d,int h){
    int i,sum1,sum2,judge=1;
    for(i=0;i<h&&judge;i++){
        sum1=sum2=0;judge=0;
        for(int j=0;j<d;j++){
            if(datadisk[j][i]=='1')sum1+=1;
            else if(datadisk[j][i]=='0');
            else sum2+=1;
        }
        for(int k=sum1;k<=sum1+sum2;k++){
            if(k%2==X){
                judge=1;
                break;
            }
        }
    }
    if(judge)return 1;
    else return 0;
}

int main(int argc, const char * argv[]) {
    int d,s,b,X=0,count=0;char x;
    while(cin>>d&&d){
        count++;
        cin>>s>>b>>x;
        if(x=='O'){X=1;}
        getData(d);
        if(!compare(X,d,s*b)){cout<<"Disk set "<<count<<" is invalid"<<endl;}
        else {
            cout<<"ehh"<<endl;
        }
    }
    
    return 0;
}
