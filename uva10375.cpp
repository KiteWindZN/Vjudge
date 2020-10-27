//
// Created by 张楠 on 2020/10/26.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

vector<int> prime_10375;
int vis_10375[10010];
int e_10375[10010];

void find_prime(){
    int m=sqrt(10010);
    memset(vis_10375,0, sizeof(vis_10375));
    for(int i=2;i<=m;i++){
        if(vis_10375[i]==0){
            for(int j=i*i;j<=10000;j+=i){
                vis_10375[j]=1;
            }
        }
    }
    for(int i=2;i<=10000;i++){
        if(vis_10375[i]==0){
            prime_10375.push_back(i);
        }
    }
}

void add_integer(int n,int d){
    for(int i=0;i<prime_10375.size()&&n>=prime_10375[i];i++){
        while(n%prime_10375[i]==0){
            e_10375[i]+=d;
            n/=prime_10375[i];
        }
    }
}
void add_factorial(int n,int d){
    for(int i=1;i<=n;i++){
        add_integer(i,d);
    }
}

int main_uva10375(){
    int p,q,r,s;
    find_prime();
    while(cin>>p>>q>>r>>s){
        memset(e_10375,0, sizeof(e_10375));
        add_factorial(p,1);
        add_factorial(q,-1);
        add_factorial(p-q,-1);

        add_factorial(r,-1);
        add_factorial(s,1);
        add_factorial(r-s,1);
        double ans=1;
        for(int i=0;i<prime_10375.size();i++){
            ans*=pow(prime_10375[i],e_10375[i]);
        }
        printf("%.5f\n",ans);
    }

}