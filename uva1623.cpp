//
// Created by 张楠 on 2020/10/15.
//

#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int maxn_1623=10e6+5;
int ans_1623[maxn_1623];
int full_1623[maxn_1623];

int main_uva1623(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        bool sign=true;
        memset(ans_1623,0, sizeof(ans_1623));
        memset(full_1623,0, sizeof(full_1623));
        set<int> days;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(!sign)
                continue;
            if(!x) days.insert(i);
            else{
                set<int>::iterator it=days.lower_bound(full_1623[x]);
                if(it==days.end())
                    sign= false;
                else{
                    ans_1623[*it]=x;
                    full_1623[x]=i;
                    days.erase(*it);
                }
            }
        }
        if(!sign)
            cout<<"NO"<<endl;
        else{
            bool flag=true;
            cout<<"YES"<<endl;
            for(int i=0;i<m;i++){
                if(ans_1623[i]>0||days.count(i)>0){
                    if(flag){
                        flag= false;
                    }else{
                        cout<<" ";
                    }
                    cout<<ans_1623[i];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}