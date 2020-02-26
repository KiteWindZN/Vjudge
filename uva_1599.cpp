//
// Created by 张楠 on 2020-02-01.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    int u,v,color;
    edge(int u_1,int v_1,int color_1){
        u=u_1;
        v=v_1;
        color=color_1;
    }
};

int n,m;
int visited[100005];
int dis[100005];
vector<edge> edges;
vector<int> G[100005];

void add_edge(int u,int v,int color){
    edge new_e=edge(u,v,color);
    int cur=edges.size();
    G[u].push_back(cur);
    G[v].push_back(cur);
    edges.push_back(new_e);
};

void rev_bfs(){
    memset(dis,-1, sizeof(dis));
    queue<int> q;
    q.push(n);
    dis[n]=0;
    while(q.size()>0){
        int cur=q.front();
        q.pop();
        for(int i=0;i<G[cur].size();i++){
            edge tmp_e=edges[G[cur][i]];
            int nn=(tmp_e.u==cur?tmp_e.v:tmp_e.u);
            if(dis[nn]<0){
                dis[nn]=dis[cur]+1;
                q.push(nn);
            }
        }
    }
}

void bfs_1599(){
    memset(visited,0, sizeof(visited));
    int cur_dis=dis[1];
    cout<<cur_dis<<endl;
    int cur;
    vector<int> next_v;
    next_v.push_back(1);
    while(cur_dis>0){
        vector<int> tmp_next_v;
        int color=1e9+1;
        for(int i=0;i<next_v.size();i++) {
            cur = next_v[i];
            for (int j = 0; j < G[cur].size(); j++) {
                edge tmp_e = edges[G[cur][j]];
                int nn=(cur==tmp_e.u?tmp_e.v:tmp_e.u);
                if(dis[nn]==cur_dis-1 &&tmp_e.color<color)
                    color=tmp_e.color;
            }
        }

        for(int i=0;i<next_v.size();i++){
            cur=next_v[i];
            for(int j=0;j<G[cur].size();j++){
                edge tmp_e=edges[G[cur][j]];
                int nn=(cur==tmp_e.u?tmp_e.v:tmp_e.u);
                if(dis[nn]==cur_dis-1 && visited[nn]==0 && tmp_e.color==color){
                    tmp_next_v.push_back(nn);
                    visited[nn]=1;
                }
            }
        }
        next_v=tmp_next_v;
        if(cur_dis!=dis[1])
            cout<<' ';
        cout<<color;
        cur_dis--;
    }
    cout<<endl;
}

int main_uva1599(){
    while(cin>>n>>m){
        edges.clear();
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=0;i<m;i++){
            int u,v,c;
            cin>>u>>v>>c;
            add_edge(u,v,c);
        }

        rev_bfs();
        bfs_1599();
    }
    return 0;
}

