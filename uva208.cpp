//
// Created by 张楠 on 2020/5/1.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn_208=21;
map<int,vector<int>> graph_208;
int visited_208[maxn_208];
int ans_208=0;
int des_208;
int res_208[maxn_208];

bool reach_208(){
    int visited[21];
    memset(visited,0, sizeof(visited));
    queue<int> q;
    q.push(1);
    visited[1]=1;
    while(q.size()>0){
        int n=q.front();
        q.pop();
        if(n==des_208)
            return true;
        vector<int> v=graph_208[n];
        for(int i=0;i<v.size();i++){
            if(visited[v[i]]==0){
                q.push(v[i]);
                visited[v[i]]=1;
            }
        }
    }
    return false;
}

void solve_208(int cur,int curI){
    if(cur==des_208){
        cout<<1;
        for(int i=1;i<curI;i++){
            cout<<" "<<res_208[i];
        }
        cout<<endl;
        ans_208++;
        return;
    }
    vector<int> curV=graph_208[cur];
    for(int i=0;i<curV.size();i++){
        if(visited_208[curV[i]]==0){
            res_208[curI]=curV[i];
            visited_208[curV[i]]=1;
            solve_208(curV[i],curI+1);
            visited_208[curV[i]]=0;
        }
    }
}

int main_uva208(){
    int count=1;
    while(cin>>des_208){
        int s,e;
        cin>>s>>e;
        ans_208=0;
        graph_208.clear();
        memset(visited_208,0, sizeof(visited_208));
        while(s!=0 && e!=0){
            graph_208[s].push_back(e);
            graph_208[e].push_back(s);
            cin>>s>>e;
        }
        for(map<int,vector<int>>::iterator key=graph_208.begin();key!=graph_208.end();key++){
            sort(key->second.begin(),key->second.end());
        }
        visited_208[1]=1;
        res_208[0]=1;
        cout<<"CASE "<<count<<":"<<endl;
        if(reach_208()){
            solve_208(1,1);
        }

        count++;
        cout<<"There are "<<ans_208<<" routes from the firestation to streetcorner "<<des_208<<"."<<endl;
    }
}
