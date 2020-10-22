//
// Created by 张楠 on 2020/10/20.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int block_437[35][3];
int dp_437[35][3];
int graph_437[35][3][35][3];
int main_uva437(){
    int n;
    cin>>n;
    int count=0;
    while(n>0){
        count++;
        memset(graph_437,0, sizeof(graph_437));
        for(int i=0;i<n;i++){
            cin>>block_437[i][0]>>block_437[i][1]>>block_437[i][2];
        }
        for(int i=0;i<n;i++){
            for(int g=0;g<3;g++){
                for(int j=0;j<n;j++){
                    for(int h=0;h<3;h++){
                        int w1,w2,h1,h2;
                        if(g==0){
                            w1=block_437[i][1];
                            h1=block_437[i][2];
                        }else if(g==1){
                            w1=block_437[i][0];
                            h1=block_437[i][2];
                        }else if(g==2){
                            w1=block_437[i][0];
                            h1=block_437[i][1];
                        }

                        if(h==0){
                            w2=block_437[j][1];
                            h2=block_437[j][2];
                        }else if(h==1){
                            w2=block_437[j][0];
                            h2=block_437[j][2];
                        }else if(h==2){
                            w2=block_437[j][0];
                            h2=block_437[j][1];
                        }

                        if((w1<w2 && h1<h2) || (w1<h2&&h1<w2)){
                            graph_437[i][g][j][h]=1;
                        }else if((w1>w2 && h1>h2)||(w1>h2 && h1>w2)){
                            graph_437[j][h][i][g]=1;
                        }
                    }
                }
            }
        }
        memset(dp_437,0, sizeof(dp_437));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                dp_437[i][j]=block_437[i][j];
                ans=max(ans,dp_437[i][j]);
            }
        }

        queue<int> indexQ;
        queue<int> orderQ;
        for(int i=0;i<n;i++){
            for(int g=0;g<3;g++){
                int flag=0;
                for(int j=0;j<n;j++){
                    for(int h=0;h<3;h++){
                        if(graph_437[j][h][i][g]){
                            // dp_437[j][h]=min(dp_437[j][h],dp_437[i][g]+block_437[j][h]);
                            // ans=max(ans,dp_437[j][h]);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1){
                        break;
                    }
                }
                if(flag==0){
                    indexQ.push(i);
                    orderQ.push(g);
                }
            }
        }

        while(indexQ.size()>0){
            int i=indexQ.front();
            indexQ.pop();
            int g=orderQ.front();
            orderQ.pop();

            for(int j=0;j<n;j++){
                for(int h=0;h<3;h++){
                    if(graph_437[i][g][j][h]){
                        if(dp_437[j][h]<dp_437[i][g]+block_437[j][h]){
                            dp_437[j][h]=max(dp_437[j][h],dp_437[i][g]+block_437[j][h]);
                            indexQ.push(j);
                            orderQ.push(h);
                        }
                        ans=max(ans,dp_437[j][h]);
                    }
                }
            }
        }
        cout<<"Case "<<count<<": maximum height = ";
        cout<<ans<<endl;

        cin>>n;
    }


    return 0;
}