//
// Created by 张楠 on 2020/4/25.
//

#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int maxn_1374=0;
set<int> ans_set;
int n_1374;
int A_1374[35];
bool solve_1374(int cur,int n){
    if(cur>maxn_1374 || n<=0 || n<<(maxn_1374-cur)<n_1374){
        return false;
    }
    if(n==n_1374 || n<<(maxn_1374-cur)==n_1374)
        return true;

    A_1374[cur]=n;
    for(int i=0;i<=cur;i++){
        if(solve_1374(cur+1,n+A_1374[i]))
            return true;
        if(solve_1374(cur+1,n-A_1374[i]))
            return true;
    }
    return false;
}

int main_uva1374(){
    int n;
    while(cin>>n_1374){
        for(maxn_1374=0;!solve_1374(0,1);maxn_1374++);
        cout<<maxn_1374<<endl;
    }
}