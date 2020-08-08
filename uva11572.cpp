//
// Created by 张楠 on 2020/8/8.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxd_11572=1000000+5;
int nums_11572[maxd_11572];
set<int> set_11572;
int main_11572(){
    int T;
    cin>>T;
    int n;
    int count=0;
    while(T>0){
        count=0;
        set_11572.clear();
        cin>>n;
        if(n>0)
            count=1;
        for(int i=0;i<n;i++){
            cin>>nums_11572[i];
        }
        int L=0,R=0;
        for(R=0;R<n;R++){
            int num=nums_11572[R];
            if(set_11572.count(num)==0){
                set_11572.insert(num);
            }else{
                if(count<set_11572.size()){
                    count=set_11572.size();
                }
                while(set_11572.count(num)!=0){
                    set_11572.erase(nums_11572[L++]);
                }
                set_11572.insert(num);
            }
            if(R==n-1){
                if(count<set_11572.size())
                    count=set_11572.size();
            }
        }
        cout<<count<<endl;
        T--;
    }
}