//
// Created by 张楠 on 2020-02-17.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string strs,string index,vector<int> squence){
    int len=strs.length();
    int start=0;
    int end=len-1;
    for(int i=0;i<squence.size();i++){
        int tmp_num=index[squence[i]]-'0';
        int mid=(start+end)/2;
        if(tmp_num==0)
            end=mid;
        else
            start=mid+1;
    }
    cout<<strs[start];
}

int main_uva712(){
    int n;
    cin>>n;
    int count=1;
    while(n>0){
        cout<<"S-Tree #"<<count<<":"<<endl;
        string tmp_str;
        string strs;
        vector<int> squence;
        for(int i=0;i<n;i++){
            cin>>tmp_str;
            squence.push_back(tmp_str[1]-'0'-1);
        }
        cin>>strs;

        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>tmp_str;
            solve(strs,tmp_str,squence);
        }
        cout<<endl<<endl;
        cin>>n;

        count++;
    }
    return 0;
}
/*
3
x2 x1 x3
01234567
4
000
010
111
110
2
x2 x1
0101
4
00
01
10
11
0
*/