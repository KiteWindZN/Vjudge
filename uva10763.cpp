//
// Created by 张楠 on 2019-12-05.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main_10763(){
    int num;
    cin>>num;
    while(num!=0){
        map<int,vector<int>> my_map;
        for(int i=0;i<num;i++){
            int num1,num2;
            cin>>num1>>num2;
            my_map[num1].push_back(num2);
        }
        map<int,vector<int>>::iterator it;
        for(it=my_map.begin();it!=my_map.end();it++){
            sort(it->second.begin(),it->second.end());
        }
        int flag=0;
        for(it=my_map.begin();it!=my_map.end();it++){
            int key=it->first;
            vector<int> list=it->second;
            for(int i=0;i<list.size();i++){
                int value=list[i];
                if(my_map.count(value)!=0 && my_map[value].size()>0 && my_map[value][0]==key){
                    my_map[value].erase(my_map[value].begin());
                }else{
                    flag=1;
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }

        cin>>num;
    }
    return 0;
}