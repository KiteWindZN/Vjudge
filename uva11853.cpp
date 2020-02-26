//
// Created by 张楠 on 2020-02-14.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iomanip>
#define  rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const int N=1005;
const double W=1000.0;
const double EPS=1e-8;

int n,vis[N];
double x[N],y[N],r[N],_left=1000.0,_right=1000.0;
bool jud;

bool notMoreThan(double a,double b){
    return (a<b) || (fabs(a-b)<EPS);
}

bool notApart(int c1,int c2){
    double a=sqrt(pow(x[c1]-x[c2],2)+pow(y[c1]-y[c2],2));
    double b=r[c1]+r[c2];
    return notMoreThan(a,b);
}

void renewCircle(int u){
    if(notMoreThan(x[u],r[u]))
        _left=min(_left,y[u]-sqrt(pow(r[u],2)-pow(x[u],2)));
    if(notMoreThan(W-x[u],r[u]))
        _right=min(_right,y[u]-sqrt(pow(r[u],2)-pow(W-x[u],2)));
}

bool dfs(int u){
    if(vis[u]) return false;
    vis[u]=1;

    if(notMoreThan(y[u],r[u])) return true;

    rep(v,n)
        if(notApart(v,u) && dfs(v)) return true;

    renewCircle(u);
    return false;
}

void solve(){
    while(cin>>n){
        jud=true;
        _left=W;
        _right=W;
        memset(vis,0, sizeof(vis));
        rep(i,n)
            cin>>x[i]>>y[i]>>r[i];
        rep(i,n)
            if(y[i]+r[i]>=W && dfs(i)){
                jud= false;
                break;
            }
        if(jud)
            cout<<"0.00 "<<fixed<<setprecision(2) << _left << " " << W << " " << _right << endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
}
int main_uva11853(){
    solve();
    return 0;
}