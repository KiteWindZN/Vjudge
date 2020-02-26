//
// Created by 张楠 on 2020-01-31.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int G[100][100];
int visited[100];
int ID(char a,char b){
    return (a-'A')*2+(b=='+'?1:0);
}
void connect(char a1,char b1,char a2,char b2){
    if(a1=='0'||b1=='0')
        return;
    int u=ID(a1,b1)^1;
    int v=ID(a2,b2);
    G[u][v]=1;
}

bool dfs(int x){
    visited[x]=-1;
    for(int i=0;i<52;i++){
        if(G[x][i]){
            if(visited[i]<0){
                return true;
            }else if(visited[i]==0 && dfs(i))
                return true;
        }
    }
    visited[x]=1;
    return false;
}

bool solve_1572(){
    memset(visited,0, sizeof(visited));
    for(int i=0;i<52;i++){
        if(visited[i])
            continue;
        if(dfs(i))
            return true;
    }
    return false;
}

int main_1572(){
    int n;
    string str;
    while(cin>>n){
        memset(G,0, sizeof(G));
        for(int i=0;i<n;i++){
            cin>>str;
            for(int i=0;i<8;i+=2){
                for(int j=0;j<8;j+=2){
                    if(i!=j)
                        connect(str[i],str[i+1],str[j],str[j+1]);
                }
            }
        }

        if(solve_1572())
            printf("unbounded\n");
        else
            printf("bounded\n");

    }
    return 0;
}