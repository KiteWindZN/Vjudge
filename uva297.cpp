//
// Created by 张楠 on 2020-01-28.
//
/*
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int len=32;
int buf[32][32];
int cnt=0;


void draw(string str,int& p,int r,int c,int w){
    char ch=str[p++];
    if(ch=='p'){
        draw(str,p,r,c+w/2,w/2);
        draw(str,p,r,c,w/2);
        draw(str,p,r+w/2,c,w/2);
        draw(str,p,r+w/2,c+w/2,w/2);
    }else if(ch=='f'){
        for(int i=r;i<r+w;i++){
            for(int j=c;j<c+w;j++){
                if(buf[i][j]==0){
                    buf[i][j]=1;
                    cnt++;
                }
            }
        }
    }
}

int main_uva297(){
    int T;
    cin>>T;
    while(T>0){
        cnt=0;
        memset(buf,0, sizeof(buf));

        for(int i=0;i<2;i++){
            string str;
            cin>>str;
            int p=0;
            draw(str,p,0,0,len);
        }
        cout<<"There are "<<cnt<<" black pixels."<<endl;
        T--;
    }

    return 0;
}

 */