//
// Created by 张楠 on 2020/9/1.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int k_12627=30;

long long solve_12627(int k,int i){

    if(i==0){
        return 0;
    }
    if(k==0){
        return i;
    }
    if(i>=pow(2,k-1)){
        return 2*solve_12627(k-1,i-pow(2,k-1))+pow(3,k-1);
    }else{
        return solve_12627(k-1,i);
    }
}

int main_uva12627(){
    int T;
    cin>>T;
    int count=1;
    int k, n,m;
    while(T--){
        cin>>k>>n>>m;

        n--;
        m--;

        long long len=pow(2,k);
        long long num=solve_12627(k,len-n)-solve_12627(k,len-m-1);
        cout<<"Case "<<count++<<": "<<num<<endl;
    }
    return 0;
}