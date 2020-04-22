//
// Created by 张楠 on 2020/4/23.
//

#include <iostream>
#include <algorithm>
using namespace std;

long long V1,S1,V2,S2;
long long N_12325;
int count_12325=1;
void solve_12325(){
    if(S2*V1>=S1*V2){
        int tmpS=S2;
        int tmpV=V2;
        S2=S1;
        V2=V1;
        S1=tmpS;
        V1=tmpV;
    }
    long long maxV=0;
    for(int i=0;i<=S2;i++){
        if(S1*i>N_12325)
            break;
        long long tmpV1=i*V1;
        long long tmpV2=(N_12325-(i*S1))/S2 * V2;
        maxV=max(maxV,tmpV1+tmpV2);
    }
    cout<<"Case #"<<count_12325<<": "<<maxV<<endl;
    count_12325++;
}
int main_uva12325(){
    int T;
    cin>>T;
    while(T--){
        cin>>N_12325>>S1>>V1>>S2>>V2;
        solve_12325();
    }
    return 0;
}