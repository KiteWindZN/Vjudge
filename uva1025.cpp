//
// Created by 张楠 on 2020/10/20.
//

#include<iostream>
#include <cstring>
#include <math.h>
using namespace std;

int train_1025[500][52][2];
int dis_1025[56];
int res_1025[206][56];
int INF_1025=1e9+7;
int main_1025(){
    int n,T;
    cin>>n;
    int index=0;
    while(n>0){
        index++;
        memset(dis_1025,0, sizeof(dis_1025));
        memset(train_1025,0, sizeof(train_1025));
        memset(res_1025,0, sizeof(res_1025));
        cin>>T;
        for(int i=0;i<n-1;i++){
            cin>>dis_1025[i];
        }
        int left,right;
        cin>>left;
        for(int i=0;i<left;i++){
            int start;
            cin>>start;
            train_1025[start][0][0]=1;
            for(int j=1;j<n;j++){
                start=start+dis_1025[j-1];
                if(start>300)
                    break;
                train_1025[start][j][0]=1;
            }
        }
        cin>>right;
        for(int i=0;i<right;i++){
            int start;
            cin>>start;
            train_1025[start][n-1][1]=1;
            for(int j=n-2;j>=0;j--){
                start+=dis_1025[j];
                if(start>300)
                    break;
                train_1025[start][j][1]=1;
            }
        }


        for(int i=0;i<n;i++){
            res_1025[T][i]=INF_1025;
        }

        res_1025[T][n-1]=0;

        for(int i=T-1;i>=0;i--){
            for(int j=0;j<n;j++){
                res_1025[i][j]=res_1025[i+1][j]+1;
                if(j<n-1 && train_1025[i][j][0]==1 && i+dis_1025[j]<=T){
                    res_1025[i][j]=min(res_1025[i][j],res_1025[i+dis_1025[j]][j+1]);
                }
                if(j>0 && train_1025[i][j][1]==1 && i+dis_1025[j-1]<T){
                    res_1025[i][j]=min(res_1025[i][j],res_1025[i+dis_1025[j-1]][j-1]);
                }
            }
        }
        if(res_1025[0][0]>=INF_1025){
            cout<<"Case Number "<<index<<": impossible"<<endl;
        }else{
            cout<<"Case Number "<<index<<": "<<res_1025[0][0]<<endl;
        }
        cin>>n;
    }
    return 0;
}