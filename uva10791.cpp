//
// Created by 张楠 on 2020/10/26.
//

#include <iostream>
#include <math.h>
using namespace std;
int main_uva10791(){

    long long n;
    cin>>n;
    int index=0;
    while(n){
        index++;
        if(n==1){

            cout<<"Case "<<index<<": ";
            cout<<2<<endl;
            cin>>n;
            continue;
        }

        int count=0;
        long long ans=0;
        int m=sqrt(n+1);
        for(int i=2;i<=m;i++){
            if(n%i==0){
                count++;
                long long tmp=1;
                while(n%i==0){
                    tmp*=i;
                    n/=i;
                }

                ans+=tmp;
            }
        }
        if(n!=1 || count==0){
            count++;
            ans+=n;
        }
        if(count==1){
            ans++;
        }
        cout<<"Case "<<index<<": ";
        cout<<ans<<endl;
        cin>>n;
    }

    return 0;
}
