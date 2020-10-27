//
// Created by 张楠 on 2020/10/25.
//

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int point_10003[1010];
int dp_10003[1010][1010];
const int INS_10003=1e9+9;
int main_uva10003(){
    int n,len;
    cin>>len;
    while(len!=0){
        cin>>n;
        point_10003[0]=0;
        point_10003[n+1]=len;
        for(int i=1;i<=n;i++){
            cin>>point_10003[i];
        }
        memset(dp_10003,INS_10003, sizeof(dp_10003));
        dp_10003[0][0]=0;

        for(int i=0;i<=n+1;i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j || i == (j + 1)) {
                    dp_10003[j][i] = 0;
                    continue;
                }
            }
        }

        for(int i=0;i<=n+1;i++){
            for(int j=i-1;j>=0;j--){
                if(i==j||i==(j+1)){
                    //dp_10003[i][j]=0;
                    continue;
                }
                for(int h=j+1;h<i;h++){
                    dp_10003[j][i]=min(dp_10003[j][i],dp_10003[h][i]+dp_10003[j][h]+point_10003[i]-point_10003[j]);
                }
            }
        }

        cout<<"The minimum cutting is ";
        cout<<dp_10003[0][n+1]<<"."<<endl;
        cin>>len;
    }
    return 0;
}