//
// Created by 张楠 on 2020/10/26.
//

#include <iostream>

using namespace std;

int T_16129;
int x_16129[100*2+10];
int r_16129[10010];
int mod_16129=10001;
long long exgcd(long long a,long long b, long long &x,long long &y){
    if(!b){
        x=1;y=0;
        return a;
    }
    long long d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main_uva16129(){
    cin>>T_16129;

    for(int i=1;i<=2*T_16129;i+=2){
        cin>>x_16129[i];
    }

    for(long long a=0;a<10001;a++){
        long long c=x_16129[3]-x_16129[1]*a*a;
        long long b,y;
        long long d=exgcd(a+1,mod_16129,b,y);
        if(c%d)
            continue;
        b*=c/d;
        r_16129[1]=x_16129[1];
        int flag=1;

        for(int i=2;i<=2*T_16129;i++){
            r_16129[i]=(r_16129[i-1]*a+b)%mod_16129;
            if(i%2==1 && r_16129[i]!=x_16129[i]){
                flag=0;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    for(int i=2;i<=2*T_16129;i+=2){
        cout<<r_16129[i]<<endl;
    }

    return 0;
}