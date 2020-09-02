//
// Created by 张楠 on 2020/8/14.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main_uva11300(){
    int n;
    while(cin>>n){
        long long A[n];
        long long C[n];
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>A[i];
            sum+=A[i];
        }
        long M=sum/n;
        C[0]=0;

        for(int i=1;i<n;i++){
            C[i]=C[i-1]+A[i]-M;
        }
        sort(C,C+n);
        long long x1=C[n/2];
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(x1-C[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}