//
// Created by 张楠 on 2020/4/18.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int w,h,n;
char pic_1601[20][20];
int num_1601[20][20];
int vis_1601[200][200][200];
int connect_1601[200][200];
int all;

int que_1601[10000000][4];
int goal_1601[4];

void BFS_1601(){
    memset(vis_1601,0, sizeof(vis_1601));
    int fro=0,rear=1;
    vis_1601[que_1601[0][1]][que_1601[0][2]][que_1601[0][3]]=1;

    while(fro<rear){
        int step=que_1601[fro][0],a=que_1601[fro][1],
                b=que_1601[fro][2],c=que_1601[fro][3];
        if(a==goal_1601[1] && b==goal_1601[2] && c==goal_1601[3]){
            goal_1601[0]=step;
            return;
        }

        for(int i=0,t1;i<=connect_1601[a][0];i++){
            t1=(i==0?a:connect_1601[a][i]);
            for(int j=0,t2;j<=connect_1601[b][0];j++){
                t2=(j==0?b:connect_1601[b][j]);
                for(int k=0,t3;k<=connect_1601[c][0];k++){
                    t3=(k==0?c:connect_1601[c][k]);
                    if((t1&& t2 &&t1==t2) ||(t2&&t3&& t2==t3)||(t1&&t3&&t1==t3)){
                        continue;
                    }
                    if(t1 && t2 && t1==b && t2==a)
                        continue;
                    if(t2 && t3 && t2==c && t3==b)
                        continue;
                    if(t1 && t3 && t1==c && t3==a)
                        continue;
                    if(vis_1601[t1][t2][t3]==0){
                        vis_1601[t1][t2][t3]=1;
                        que_1601[rear][0]=step+1;
                        que_1601[rear][1]=t1;
                        que_1601[rear][2]=t2;
                        que_1601[rear][3]=t3;
                        rear++;
                    }
                }
            }
        }
        fro++;
    }
}

int main_uva1601(){
    int _t=0;
    while(scanf("%d%d%d",&w,&h,&n)&&w&&h&&n){
        gets(pic_1601[0]);
        for(int i=0;i<h;i++)
            gets(pic_1601[i]);
        memset(connect_1601,0, sizeof(connect_1601));
        all=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(pic_1601[i][j]!='#')
                    num_1601[i][j]=++all;
                else num_1601[i][j]=0;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){

                int pos=num_1601[i][j];
                if(pos==0)
                    continue;
                if(num_1601[i+1][j])
                    connect_1601[pos][++connect_1601[pos][0]]=num_1601[i+1][j];
                if(num_1601[i-1][j])
                    connect_1601[pos][++connect_1601[pos][0]]=num_1601[i-1][j];
                if(num_1601[i][j+1])
                    connect_1601[pos][++connect_1601[pos][0]]=num_1601[i][j+1];
                if(num_1601[i][j-1])
                    connect_1601[pos][++connect_1601[pos][0]]=num_1601[i][j-1];
            }
        }

        que_1601[0][0]=que_1601[0][1]=que_1601[0][2]=que_1601[0][3]=0;
        goal_1601[0]=goal_1601[1]=goal_1601[2]=goal_1601[3]=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(islower(pic_1601[i][j])){
                    if(pic_1601[i][j]=='a')
                        que_1601[0][1]=num_1601[i][j];
                    if(pic_1601[i][j]=='b')
                        que_1601[0][2]=num_1601[i][j];
                    if(pic_1601[i][j]=='c')
                        que_1601[0][3]=num_1601[i][j];
                }
                if(isupper(pic_1601[i][j])){
                    if(pic_1601[i][j]=='A')
                        goal_1601[1]=num_1601[i][j];
                    if(pic_1601[i][j]=='B')
                        goal_1601[2]=num_1601[i][j];
                    if(pic_1601[i][j]=='C')
                        goal_1601[3]=num_1601[i][j];
                }

            }
        }
        BFS_1601();
        cout<<goal_1601[0]<<endl;
    }
    return 0;
}

