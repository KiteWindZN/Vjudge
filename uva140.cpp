//
// Created by 张楠 on 2020/4/1.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;

int visited_140[8];
int kmin_140=8;
int num_140=0;
int kcur_140=0;
int res_140[8];
int tmp_140[8];
map<char,set<char>> graph_140;
vector<int> nodes_140;


void println(){
    for(int i=0;i<num_140;i++){
        char ch=res_140[i]+'A';
        cout<<ch<<" ";
    }
    cout<<"-> "<<kmin_140<<endl;
}

void solve_140(int index){

    if(index==num_140){
        if(kcur_140<kmin_140){
            for(int i=0;i<index;i++){
                res_140[i]=tmp_140[i];
                kmin_140=kcur_140;
            }
        }
        return ;
    }

    for(int i=0;i<num_140;i++){
        int cur_i=nodes_140[i]-'A';
        if(visited_140[cur_i]==-1){
            int tmpDis=0;

            for(char ch:graph_140[nodes_140[i]]){
                int j=ch-'A';
                if(visited_140[j]>-1){
                    int tmp=index-visited_140[j];
                    if(tmpDis<tmp)
                        tmpDis=tmp;
                }
            }

            if(tmpDis>=kmin_140){
                continue;
            }else{
                visited_140[cur_i]=index;
                tmp_140[index]=cur_i;
                int last_kcur=kcur_140;
                if(kcur_140<tmpDis)
                    kcur_140=tmpDis;
                solve_140(index+1);
                visited_140[cur_i]=-1;
                tmp_140[index]=-1;
                kcur_140=last_kcur;
            }
        }
    }
}


int main_uva140(){
    string line;
    getline(cin,line);
    while(line!="#"){
        memset(visited_140,-1, sizeof(visited_140));
        graph_140.clear();
        nodes_140.clear();
        memset(tmp_140,-1, sizeof(tmp_140));
        for(int i=0;i<line.length();i++){
            char ch=line[i];
            char start=ch;
            i++;
            i++;
            while(line[i]!=';'&&i<line.length()){
                ch=line[i];
                graph_140[start].insert(ch);
                graph_140[ch].insert(start);
                i++;
            }
        }
        num_140=graph_140.size();
        for(auto p:graph_140){
            nodes_140.push_back(p.first);
        }
        sort(nodes_140.begin(),nodes_140.end());

        solve_140(0);
        println();
        getline(cin,line);
    }
    return 0;
}