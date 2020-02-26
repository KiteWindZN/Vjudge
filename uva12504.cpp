//
// Created by 张楠 on 2019-12-19.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

void print_set(set<string> s_set,int index){
    if(s_set.size()==0)
        return;
    if(index==0)
        cout<<"+";
    if(index==1)
        cout<<"-";
    if(index==2)
        cout<<"*";
    set<string>::iterator it=s_set.begin();
    cout<<*it;
    it++;
    for(;it!=s_set.end();it++){
        cout<<",";
        cout<<*it;
    }
    cout<<endl;

}

int main_12504(){
    int N;
    cin>>N;
    getchar();
    for(int j=0;j<N;j++){

        string key,value,line;
        map<string,string> map_1;
        map<string,string> map_2;

        getline(cin,line);
        for(int i=1;i<line.length()-1;i++){
            key="";
            value="";
            while(line[i]!=':'){
                key=key+line[i];
                i++;
            }
            i++;
            while(line[i]!=',' && line[i]!='}'){
                value=value+line[i];
                i++;
            }
            map_1[key]=value;
        }
        getline(cin,line);
        for(int i=1;i<line.length()-1;i++){
            key="";
            value="";
            while(line[i]!=':'){
                key=key+line[i];
                i++;
            }
            i++;
            while(line[i]!=',' && line[i]!='}'){
                value=value+line[i];
                i++;
            }
            map_2[key]=value;
        }
        set<string> add_set;
        set<string> change_set;
        set<string> delete_set;

        map<string,string>::iterator it=map_2.begin();
        for(;it!=map_2.end();it++){
            key=it->first;
            value=map_2[key];

            if(map_1.count(key)==0){
                add_set.insert(key);
            }else if(map_2[key]!=map_1[key]){
                change_set.insert(key);
            }
        }

        map<string,string>::iterator it_1=map_1.begin();
        for(;it_1!=map_1.end();it_1++){
            key=it_1->first;
            value=map_1[key];

            if(map_2.count(key)==0){
                delete_set.insert(key);
            }
        }

        if(add_set.size()==0 && delete_set.size()==0 && change_set.size()==0){
            cout<<"No changes"<<endl;
            cout<<endl;
        }else{
            print_set(add_set,0);
            print_set(delete_set,1);
            print_set(change_set,2);
            cout<<endl;
        }
    }

    return 0;
}