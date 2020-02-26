//
// Created by 张楠 on 2019-11-29.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main_1022(){
    int N;
    cin>>N;
    map<string,set<string>> my_map[6];


    for(int i=0;i<N;i++){
        string id;
        cin.get();
        getline(cin,id);
        string line;

        getline(cin,line);
        my_map[1][line].insert(id);

        getline(cin,line);
        my_map[2][line].insert(id);

        getline(cin,line);
        stringstream ss(line);
        string keyword;
        while(ss>>keyword)
            my_map[3][keyword].insert(id);

        getline(cin,line);
        my_map[4][line].insert(id);

        cin>>line;
        my_map[5][line].insert(id);
    }
    int M;
    cin>>M;
    cin.get();
    for(int i=0;i<M;i++){
        int num;
        string str,str1;
        getline(cin,str1);
        num=str1[0]-'0';
        str=str1.substr(3);
        cout<<str1<<endl;
        if(my_map[num][str].size()){
            set<string>::iterator it;
            for(it=my_map[num][str].begin();it!=my_map[num][str].end();it++){
                cout<<*it<<endl;
            }
        } else
            cout<<"Not Found"<<endl;
    }
    return 0;
}