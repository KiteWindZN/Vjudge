//
// Created by 张楠 on 2020-02-02.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> installed;
vector<string> all_name;
map<string,int> name_int;
const int max_506=102401;
vector<int> deep1[max_506];
vector<int> deep2[max_506];
int status[max_506];

int get_id(string name){
    if(name_int.count(name)==0){
        int len=all_name.size();
        all_name.push_back(name);
        name_int[name]=len;
    }
    return  name_int[name];
}

void Install(int item,bool toplevel){
    if(status[item] && toplevel){
        cout<<"   "<<all_name[item]<<" is already installed."<<endl; return;
    }
    if(status[item]) return;
    for(int i=0;i<deep1[item].size();i++){
        Install(deep1[item][i],false);
    }
    cout<<"   Installing "<<all_name[item]<<endl;
    installed.push_back(item);
    status[item]=toplevel?1:2;
}

bool needed(int item){
    for(int i=0;i<deep2[item].size();i++){
        if(status[deep2[item][i]])
            return true;
    }
    return false;
}

void Remove(int item,bool toplevel){

    if(status[item]==0&& toplevel){
        cout<<"   "<<all_name[item]<<" is not installed."<<endl;
        return;
    }
    if((toplevel || status[item]==2)&& !needed(item)){

        installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
        cout<<"   Removing "<<all_name[item]<<endl;
        status[item]=0;
        for(int i=deep1[item].size()-1;i>=0;i--){
            //for(int i=0;i<deep1[item].size();i++){
            Remove(deep1[item][i],false);
        }
        return;
    }
    if(toplevel)  cout<<"   "<<all_name[item]<<" is still needed."<<endl;
}



int main_uva506(){
    string line;
    memset(status,0, sizeof(status));

    while(getline(cin,line)){
        cout<<line<<endl;
        if(line=="END"){
            break;
        }
        stringstream ss(line);
        string str;
        ss>>str;
        if(str=="DEPEND"){

            string name;
            ss>>name;
            if(name_int.count(name)==0){
                int len=all_name.size();
                all_name.push_back(name);
                name_int[name]=len;
            }

            while(ss>>str){
                int len=all_name.size();
                if(name_int.count(str)==0){
                    all_name.push_back(str);
                    name_int[str]=len;
                } else
                    len=name_int[str];

                deep1[name_int[name]].push_back(len);
                deep2[len].push_back(name_int[name]);
            }

        } else if(str=="INSTALL"){
            ss>>str;
            Install(get_id(str), true);

        } else if(str=="LIST"){
            for(int i=0;i<installed.size();i++){
                cout<<"   "<<all_name[installed[i]]<<endl;
            }

        }else if(str=="REMOVE"){
            string name;
            ss>>name;

            Remove(get_id(name),true);
        }

    }
    return 0;
}
