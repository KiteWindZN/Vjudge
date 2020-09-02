//
// Created by 张楠 on 2020/9/1.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxd_1471=200000+10;
int nums_1471[maxd_1471];
int start_1471[maxd_1471];
int end_1471[maxd_1471];

int main_1471(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>nums_1471[i];
        }
        memset(start_1471,0, sizeof(start_1471));
        memset(end_1471,0, sizeof(end_1471));
        start_1471[0]=1;
        end_1471[n-1]=1;
        for(int i=1;i<n;i++){
            if(nums_1471[i]>nums_1471[i-1]){
                start_1471[i]=start_1471[i-1]+1;
            }else{
                start_1471[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums_1471[i]<nums_1471[i+1]){
                end_1471[i]=end_1471[i+1]+1;
            }else{
                end_1471[i]=1;
            }
        }

        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int num=0;
                if(nums_1471[i]<=nums_1471[j]){
                    num=start_1471[i]+end_1471[j];
                    if(nums_1471[i]==nums_1471[j]){
                        num--;
                    }
                    ans=max(ans,num);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}