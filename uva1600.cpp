#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int vis_1600[30][30];
int map_1600[30][30];

int dx_1600[]={1,0,-1,0};
int dy_1600[]={0,1,0,-1};

int T_1600,m_1600,n_1600,kk;
struct Point6{
    int x, y, step, k;
    Point6(int x,int y,int step,int k):x(x),y(y),step(step),k(k){}
};

int BFS_1600(){
    memset(vis_1600,0, sizeof(vis_1600));
    queue<Point6> q;
    q.push(Point6(0,0,0,kk));
    while(q.size()){
        int x=q.front().x;
        int y=q.front().y;

        if(x==m_1600-1 && y==n_1600-1)
            return q.front().step;
        vis_1600[x][y]=1;
        for(int i=0;i<4;i++){
            int mx=x+dx_1600[i];
            int my=y+dy_1600[i];
            if(mx<0||mx>=m_1600 || my<0 || my>=n_1600 || vis_1600[mx][my]==1)
                continue;
            if(map_1600[mx][my]==0){
                q.push(Point6(mx,my,q.front().step+1,kk));
            }
            if(map_1600[mx][my]==1 && q.front().k >0){
                q.push(Point6(mx,my,q.front().step+1,q.front().k-1));
            }
        }
        q.pop();
    }
    return -1;
}

int main_uva1600_1(){

    while(cin>>T_1600){
        while(T_1600>0){
            scanf("%d%d%d",&m_1600,&n_1600,&kk);
            for(int i=0;i<m_1600;i++){
                for(int j=0;j<n_1600;j++){
                    cin>>map_1600[i][j];
                }
            }
            cout<<BFS_1600()<<endl;
            T_1600--;
        }
    }
    return 0;
}