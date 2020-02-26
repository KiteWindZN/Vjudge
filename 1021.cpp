//
// Created by 张楠 on 2019-11-28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

struct Node{
    int id;
    vector<int> children;

};

void get_deepest_root(vector<Node> nodes){
    vector<int> res;
    int start=1;
    int ret=1;
    queue<int> q;
    queue<int> level;
    q.push(start);
    level.push(1);
    int N=nodes.size();
    int visited[N];
    memset(visited,0, sizeof(visited));
    res.push_back(start);
    visited[1]=1;
    while(q.size()){
        int cur=q.front();
        q.pop();
        ret =level.front();
        level.pop();
        vector<int> children=nodes[cur].children;
        for(int i:children){
            if(visited[i]==0){
                q.push(i);
                level.push(ret+1);
                visited[i]=ret+1;
                if(ret+1>visited[res[0]])
                    res.clear();
                res.push_back(i);
            }
        }
    }

    start=res[0];

    vector<int> res_1;

    queue<int> q_1;
    queue<int> level_1;
    q_1.push(start);
    level_1.push(1);


    memset(visited,0, sizeof(visited));
    res_1.push_back(start);
    visited[start]=1;
    while(q_1.size()){
        int cur=q_1.front();
        q_1.pop();
        ret =level_1.front();
        level_1.pop();
        vector<int> children=nodes[cur].children;
        for(int i:children){
            if(visited[i]==0){
                q_1.push(i);
                level_1.push(ret+1);
                visited[i]=ret+1;
                if(ret+1>visited[res_1[0]])
                    res_1.clear();
                res_1.push_back(i);
            }
        }
    }

    set<int> S;
    for(int i: res){
        S.insert(i);
    }
    for(int i: res_1){
        S.insert(i);
    }

    set<int>::iterator it=S.begin();
    for(;it!=S.end();it++){
        cout<<*it<<endl;
    }

}

int find(int x,vector<int> &flag){
    if(x==flag[x])
        return x;
    else return find(flag[x],flag);
}

void merge(int x,int y,vector<int> &flag){
    int cur_x=find(x,flag);
    int cur_y=find(y,flag);
    if(cur_x!=cur_y){
        int root=cur_x;
        if(cur_x<cur_y){
            while(y!=cur_y){
                y=flag[y];
                flag[y]=root;
            }
            flag[cur_y]=root;
        }else{
            root=cur_y;
            while(x!=cur_x){
                x=flag[x];
                flag[x]=root;
            }
            flag[cur_x]=root;
        }
    }
}

bool is_ok(vector<int> flag){
    int count=0;
    int N=flag.size();
    for(int i=1;i<N;i++){
        if(flag[i]==i)
            count++;
    }
    if(count>=2){
        cout<<"Error: "<<count<<" components"<<endl;
        return false;
    }
    return true;
}

int main_1021(){
    int N;
    cin>>N;
    vector<int> flag(N+1);
    for(int i=0;i<N+1;i++){
        flag[i]=i;
    }
    vector<Node> nodes(N+1);
    for(int i=0;i<N-1;i++){
        int start,end;
        cin>>start>>end;
        nodes[start].id=start;
        nodes[end].id=end;
        nodes[start].children.push_back(end);
        nodes[end].children.push_back(start);
        merge(start,end,flag);
    }
    if(is_ok(flag)){
        get_deepest_root(nodes);
    }

    return 0;
}