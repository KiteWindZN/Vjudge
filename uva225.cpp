//
// Created by 张楠 on 2020/5/2.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int step_225;
const int max_step=20;

int res_225[max_step];
int ans_225=0;
int visited_225[250][250];
const int MAXN_225=105;
int gra_225[350][350];
int dx_225[]={1,0,0,-1};
int dy_225[]={0,1,-1,0};
const char direction_225[]="ensw";
//wsenenws

int check_225(int curx,int cury,int curd,int direct){
    for(int i=0;i<curd;i++){
        curx+=dx_225[direct];
        cury+=dy_225[direct];

        if(gra_225[curx][cury]==1){
            return 0;
        }
    }
    int step = 0;
    for(int i = curd+1;i <= step_225;i++) step += i;
    if(abs(curx-MAXN_225)+abs(cury-MAXN_225) > step) return 0;
    return 1;

}

void  dfs_225(int curx,int cury,int curd,int direct){
    if(curd>step_225+1)
        return;
    if(curx==MAXN_225&& cury==MAXN_225 && curd>1){
        if(curd-1==step_225){
            ans_225++;
            for(int i=0;i<curd-1;i++){
                cout<<direction_225[res_225[i]];
            }
            cout<<endl;
        }
        return;
    }

    for(int i=0;i<4;i++){
        int tx=curx+dx_225[i]*curd;
        int ty=cury+dy_225[i]*curd;
        if(gra_225[tx][ty]==0&&i!=direct&&i+direct!=3&&check_225(curx,cury,curd,i)
           && visited_225[tx][ty]==0){
            res_225[curd-1]=i;
            visited_225[tx][ty]=1;
            dfs_225(tx,ty,curd+1,i);
            visited_225[tx][ty]=0;
        }
    }
}

int main_uva225(){
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
        dfs_225(MAXN_225,MAXN_225,1,-1);
        cout<<"Found "<<ans_225<<" golygon(s)."<<endl<<endl;
    }
    return 0;
}