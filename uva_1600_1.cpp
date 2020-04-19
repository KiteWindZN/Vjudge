//
// Created by 张楠 on 2020-03-07.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int count_1600[30][30];
int visited_1600[30][30];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int map_1600[30][30];
int m_1600,n_1600,k_1600;
/*
int BFS()
{   memset(vis,false,sizeof(vis));

    queue<point> q;
    q.push(point(0,0,0,kk));

    int x,y;
    while(q.size()){
        x=q.front().x,y=q.front().y;
        if(x==m-1&&y==n-1) return q.front().step;
        vis[x][y]=true;
        for(int i=0;i<4;i++){
            int mx=dx[i]+x,my=dy[i]+y;
            if(mx<0||mx>=m||my<0||my>=n||vis[mx][my]) continue;
            if(map[mx][my]==0) q.push(point(mx,my,q.front().step+1,kk));
            if(map[mx][my]==1&&q.front().k>0) q.push(point(mx,my,q.front().step+1,q.front().k-1));
        }
        q.pop();
    }
    return -1;
}
*/
int solve_1600(int startx,int starty,int endx,int endy){
    queue<int> queue1;
    queue<int> queue2;
    int ret=0;
    queue1.push(startx);
    queue1.push(starty);
    queue2.push(ret);

    int x,y;
    while(queue1.size()>0){
        x=queue1.front();
        queue1.pop();
        y=queue1.front();
        queue1.pop();
        ret=queue2.front();
        queue2.pop();
        if(x==endx && y==endy)
            return ret;
        visited_1600[x][y]=1;
        for(int i=0;i<4;i++){
            int tmpx=x+dx[i];
            int tmpy=y+dy[i];

            if(tmpx<0 || tmpx>= m_1600 || tmpy<0 || tmpy>=n_1600 || visited_1600[tmpx][tmpy]==1){
                continue;
            }

            if(map_1600[tmpx][tmpy]==0){
                queue1.push(tmpx);
                queue1.push(tmpy);
                queue2.push(ret+1);
                count_1600[tmpx][tmpy]=k_1600;
            }

            if(map_1600[tmpx][tmpy]==1 && count_1600[x][y]>0){
                queue1.push(tmpx);
                queue1.push(tmpy);
                queue2.push(ret+1);
                count_1600[tmpx][tmpy]=count_1600[x][y]-1;
            }
        }
    }

    return -1;
}

int main_1600_1(){
    int T=0;
    while(cin>>T){
        while(T>0){

            memset(visited_1600,0,sizeof(visited_1600));
            memset(map_1600,0, sizeof(map_1600));
            cin>>m_1600>>n_1600>>k_1600;

            memset(count_1600,k_1600, sizeof(count_1600));

            for(int i=0;i<m_1600;i++){
                for(int j=0;j<n_1600;j++){
                    cin>>map_1600[i][j];
                }
            }
            int res=solve_1600(0,0,m_1600-1,n_1600-1);
            cout<<res<<endl;
            T--;
        }
    }


    return 0;
}

