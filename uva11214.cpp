#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n_11214;
int m_11214;
const int max_11214=12;
int vis_11214[4][50];
int graph_11214[max_11214][max_11214];
int maxd_11214;

bool isOK_11214(){
    for(int i=0;i<n_11214;i++){
        for(int j=0;j<m_11214;j++){
            if(graph_11214[i][j]==1&&(vis_11214[0][i]==0&&vis_11214[1][j]==0&&vis_11214[2][i-j+max_11214]==0&&vis_11214[3][i+j]==0)){
                return false;
            }
        }
    }
    return true;
}

bool dfs_11214(int i,int j,int cur){

    if(cur==(maxd_11214+1)){
        if(isOK_11214())
            return true;
        else return false;
    }
    for(;j<m_11214;j++){
        int t0,t1,t2,t3;
        t0=vis_11214[0][i];
        t1=vis_11214[1][j];
        t2=vis_11214[2][i-j+max_11214];
        t3=vis_11214[3][i+j];

        vis_11214[0][i]=1;
        vis_11214[1][j]=1;
        vis_11214[2][i-j+max_11214]=1;
        vis_11214[3][i+j]=1;

        if(dfs_11214(i,j+1,cur+1))
            return true;
        vis_11214[0][i]=t0;
        vis_11214[1][j]=t1;
        vis_11214[2][i-j+max_11214]=t2;
        vis_11214[3][i+j]=t3;
    }
    for(i=i+1;i<n_11214;i++){
        for(j=0;j<m_11214;j++){
            int t0,t1,t2,t3;
            t0=vis_11214[0][i];
            t1=vis_11214[1][j];
            t2=vis_11214[2][i-j+max_11214];
            t3=vis_11214[3][i+j];

            vis_11214[0][i]=1;
            vis_11214[1][j]=1;
            vis_11214[2][i-j+max_11214]=1;
            vis_11214[3][i+j]=1;

            if(dfs_11214(i,j+1,cur+1))
                return true;
            vis_11214[0][i]=t0;
            vis_11214[1][j]=t1;
            vis_11214[2][i-j+max_11214]=t2;
            vis_11214[3][i+j]=t3;
        }
    }
    return false;
}
int main_11214(){
    int T;
    int index=1;
    cin>>n_11214;
    while(n_11214>0){
        cin>>m_11214;
        memset(graph_11214,0,sizeof(graph_11214));
        for(int i=0;i<n_11214;i++){
            string line;
            cin>>line;

            for(int j=0;j<m_11214;j++){
                char ch=line[j];
                if(ch=='X'){
                    graph_11214[i][j]=1;
                }
            }
        }

        for(maxd_11214=1;;maxd_11214++){
            memset(vis_11214,0,sizeof(vis_11214));
            if(dfs_11214(0,0,1))
                break;
        }
        cout<<"Case "<<index<<": "<<maxd_11214<<endl;
        index++;
        cin>>n_11214;
    }
    return 0;
}

/*
8 8
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
8 8
X.......
.X......
..X.....
...X....
....X...
.....X..
......X.
.......X
0*/
