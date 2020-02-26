//
// Created by 张楠 on 2020-01-29.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int graph[101][101];

void solve(int n){
    int visited[n+1];
    memset(visited,0, sizeof(visited));

    int count=0;
    while(count<n){
        int cur=count;
        for(int i=1;i<=n;i++){
            if(visited[i]==1)
                continue;
            int flag=0;
            for(int j=1;j<=n;j++){
                if(graph[j][i]==1) {
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                if(count>0){
                    cout<<" ";
                }
                cout<<i;
                visited[i]=1;
                for(int j=0;j<=n;j++){
                    graph[i][j]=0;
                }
                count++;
            }
        }
        if(count==cur)
            return;
    }
    cout<<endl;
}

int main_uva_10305(){
    int m,n;
    cin>>n>>m;
    while(n!=0){
        memset(graph,0, sizeof(graph));
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            graph[u][v]=1;
        }
        solve(n);
        cin>>n>>m;
    }
    return 0;
}