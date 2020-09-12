//
// Created by 张楠 on 2020/9/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main_1149(){
    int T;
    cin>>T;
    int l;
    int n;
    while(T--){
        cin>>n;
        cin>>l;
        vector<int> items;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            items.push_back(tmp);
        }

        sort(items.begin(),items.end());
        int start=0;
        int end=items.size()-1;
        int ans=0;
        while(start<=end){
            int weight1=items[end];
            int weight2=items[start];
            if(weight1+weight2<=l){
                ans++;end--;start++;
            }else{
                ans++;end--;
            }
        }
        cout<<ans<<endl;
        if(T>0){
            cout<<endl;
        }
    }
    return 0;
}