//
// Created by 张楠 on 2020/10/21.
//

#include <iostream>
#include <math.h>
using namespace std;

float dist_1347[1010][1010];
int n_1347;
float dp_1347[1010][1010];
int pointx_1347[1010];
int pointy_1347[1010];

int main_uva1347(){
    while(cin>>n_1347){
        for(int i=1;i<=n_1347;i++){
            cin>>pointx_1347[i]>>pointy_1347[i];
        }
        for(int i=1;i<=n_1347;i++){
            for(int j=1;j<=n_1347;j++){
                float dis=sqrt(pow(pointx_1347[i]-pointx_1347[j],2)+pow(pointy_1347[i]-pointy_1347[j],2));
                dist_1347[i][j]=dis;
            }
        }
        float ans=0;
        for(int i=1;i<n_1347-1;i++){
            dp_1347[n_1347-1][i]=dist_1347[n_1347-1][n_1347]+dist_1347[n_1347][i];
        }
        for(int i=n_1347-2;i>1;i--){
            for(int j=1;j<i;j++){
                dp_1347[i][j]= min(dp_1347[i+1][j]+dist_1347[i][i+1], dp_1347[i+1][i]+dist_1347[i+1][j]);
            }
        }

        ans=dp_1347[2][1]+dist_1347[2][1];

        printf("%.2f\n",ans);
    }
    return 0;
}