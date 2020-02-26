//
// Created by 张楠 on 2019-11-28.
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main_10815(){
    string line;
    set<string> S;
    while(cin>>line){
        for(int i=0;i<line.length();i++){
            if(!isalpha(line[i])){
                line[i]=' ';
            } else
                line[i]=tolower(line[i]);
        }
        stringstream ss(line);
        string cur;
        while(ss>>cur){
            S.insert(cur);
        }
    }
    set<string>::iterator it=S.begin();
    for(;it!=S.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}