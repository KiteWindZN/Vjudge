//
// Created by 张楠 on 2020/8/8.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int maxd_11054=100000+5;
long long nums_11054[maxd_11054];

int main_11054(){
    int n;
    long long count=0;
    cin>>n;
    while(n>0){
        count=0;
        for(int i=0;i<n;i++){
            cin>>nums_11054[i];
            if(i>0){
                nums_11054[i]=nums_11054[i-1]+nums_11054[i];
            }
            count+=abs(nums_11054[i]);
        }
        cout<<count<<endl;
        cin>>n;
    }
    return 0;
}

/*
5
5 -4 1 -3 1
6
-1000 -1000 -1000 1000 1000 1000
0*/
