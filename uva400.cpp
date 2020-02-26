//
// Created by 张楠 on 2019-12-02.
//

#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void print(string s,int len,char extra){
    cout<<s;
    int l=s.length();
    while(l<len){
        cout<<extra;
        l++;
    }
}

int main_400(){
    int num;
    while(cin>>num){
        int Max=0;
        vector<string> q;
        for(int i=0;i<num;i++){
            string str;
            cin>>str;
            q.push_back(str);
            if(Max<str.length())
                Max=str.length();
        }
        sort(q.begin(),q.end());
        int column=(60-Max)/(Max+2)+1;
        int row=(num-1)/column+1;
        print("",60,'-');
        cout<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                int index=j*row+i;
                if(index>=num)
                    break;
                int width=0;
                if(j==column-1)
                    width=Max;
                else
                    width=Max+2;
                print(q[index],width,' ');
            }
            cout<<endl;
        }
    }
    return 0;
}