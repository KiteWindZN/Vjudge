/*
//
// Created by 张楠 on 2020/5/2.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int step_225;
const int max_step=20;

char res_225[max_step];
int ans_225=0;
int visited_225[250][250];
const int MAXN_225=105;
int gra_225[350][350];

void  dfs_225(int curx,int cury,int curd,int direct){
    if(curd>step_225+1)
        return;
    if(curx==MAXN_225&& cury==MAXN_225 && curd>1){
        if(curd-1==step_225){
            ans_225++;
            for(int i=0;i<curd-1;i++){
                cout<<res_225[i];
            }
            cout<<endl;
        }
        return;
    }

    int step = 0;
    for(int i = curd;i <= step_225;i++) step += i;
    if(abs(curx-MAXN_225)+abs(cury-MAXN_225) > step) return;

    if(direct==2){
        res_225[curd-1]='e';
        int endx=curx+curd;
        if(visited_225[endx][cury]==1)
            return;
        for(int i=curx+1;i<=endx;i++){
            if(gra_225[i][cury]==1){
                return ;
            }
        }
        visited_225[endx][cury]=1;
        if(endx==MAXN_225&&cury==MAXN_225){
            dfs_225(endx,cury,curd+1,1);
        }else {
            dfs_225(endx, cury, curd + 1, 0);
            dfs_225(endx, cury, curd + 1, 1);
        }
        visited_225[endx][cury]=0;
    }else if(direct==0){
        res_225[curd-1]='n';
        int endy=cury+curd;
        if(visited_225[curx][endy]==1)
            return;
        for(int i=cury+1;i<=endy;i++){
            if(gra_225[curx][i]==1){
                return;
            }
        }
        visited_225[curx][endy]=1;
        if(endy==MAXN_225&&curx==MAXN_225){
            dfs_225(curx,endy,curd+1,3);
        }else{
            dfs_225(curx,endy,curd+1,2);
            dfs_225(curx,endy,curd+1,3);
        }
        visited_225[curx][endy]=0;

    }else if(direct==1){//s
        res_225[curd-1]='s';
        int endy=cury-curd;
        if(visited_225[curx][endy]==1)
            return;
        for(int i=cury-1;i>=endy;i--){
            if(gra_225[curx][i]==1){
                return;
            }
        }
        visited_225[curx][endy]=1;
        if(endy==MAXN_225&&curx==MAXN_225){
            dfs_225(curx,endy,curd+1,2);
        }else {
            dfs_225(curx, endy, curd + 1, 2);
            dfs_225(curx, endy, curd + 1, 3);
        }
        visited_225[curx][endy]=0;
    }else if(direct==3){
        res_225[curd-1]='w';
        int endx=curx-curd;

        if(visited_225[endx][cury]==1)
            return;
        visited_225[endx][cury]=1;
        for(int i=curx-1;i>=endx;i--){
            if(gra_225[i][cury]==1){
                return ;
            }
        }

        if(endx==MAXN_225&&cury==MAXN_225){
            dfs_225(endx,cury,curd+1,1);
        }else {
            dfs_225(endx,cury,curd+1,0);
            dfs_225(endx,cury,curd+1,1);
        }
        visited_225[endx][cury]=0;
    }
}

void solve_225(){
    for(int i=0;i<4;i++){
        memset(visited_225,0,sizeof(visited_225));
        dfs_225(MAXN_225,MAXN_225,1,i);
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>step_225;
        int k;
        cin>>k;
        ans_225=0;

        memset(visited_225,0,sizeof(visited_225));
        memset(gra_225,0,sizeof(gra_225));
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            if(abs(x)>MAXN_225||abs(y)>MAXN_225)
                continue;
            gra_225[x+MAXN_225][y+MAXN_225]=1;
        }
        solve_225();
        cout<<"Found "<<ans_225<<" golygon(s)."<<endl<<endl;
    }
    return 0;
}*/
