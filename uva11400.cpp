//
// Created by 张楠 on 2020/10/22.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct Lamp_11400{
    int V,K,C,L;
    Lamp_11400(){
        this->V=0;
        this->K=0;
        this->C=0;
        this->L=0;
    }
    bool operator < (const Lamp_11400 &a) const
    {
        return V<a.V;
    }
};


int INS_111400=1e8+9;
int main_uva11400(){
    int n;
    cin>>n;
    while(n!=0){
        Lamp_11400 lamps[n+1];
        int dp[n+1],s[n+1];
        lamps[0].V=0;
        lamps[0].K=0;
        lamps[0].C=0;
        lamps[0].L=0;
        for(int i=1;i<=n;i++){
            cin>>lamps[i].V>>lamps[i].K>>lamps[i].C>>lamps[i].L;
            dp[i]=INS_111400;
        }
        sort(lamps+1,lamps+n+1);
        s[1]=lamps[1].L;
        s[0]=0;
        for(int i=2;i<=n;i++){
            s[i]=s[i-1]+lamps[i].L;
        }
        dp[0]=0;
        dp[1]=lamps[1].C*lamps[1].L + lamps[1].K;

        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*lamps[i].C+lamps[i].K);
            }
        }

        cout<<dp[n]<<endl;
        cin>>n;
    }

    return 0;
}