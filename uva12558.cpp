//
// Created by 张楠 on 2020/8/4.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const int maxn_12558=100000+10;

set<long long> ban_12558;
int maxed_12558;
bool ok;

ll v_12558[maxn_12558],ans_12558[maxn_12558];

ll gcd_12558(ll a,ll b){//最大公约数
    return b==0 ? a: gcd_12558(b,a%b);
}

ll get_first_12558(ll a,ll b){ //比b/a小的，最接近b/a的1/c的c
    return b/a+1;
}

bool better_12558(int d){
    for(int i=d;i>=0;i--){//从最后一个数开始判断，从后往前
        if(ans_12558[i]!=v_12558[i]){ //第一个可以满足条件的数组，或者更好的数组，（最小的数的分母尽量小）
            return ans_12558[i]==-1 || v_12558[i] < ans_12558[i];
        }
    }
    return false;
}

void dfs_12558(int cur, ll from, ll a, ll b){
    if(cur==maxed_12558){ //最后一个
        if(b%a || ban_12558.count(b/a))
            return;
        v_12558[cur]=b;
        if(better_12558(cur)) memcpy(ans_12558,v_12558,sizeof(ll)*(cur+1));
        ok= true;
        return;
    }
    from=max(from,get_first_12558(a,b));
    for(int i=from;;i++){
        if(a*i>=b*(maxed_12558-cur+1))
            return;
        if(ban_12558.count(i))
            continue;
        v_12558[cur]=i;
        ll t1=a*i- b,t2=b*i;
        ll g=gcd_12558(t1,t2);
        dfs_12558(cur+1,i+1,t1/g,t2/g);
    }
    return ;
}

int main_12558(){
    int T,t=1;
    cin>>T;
    while(T--){
        ban_12558.clear();
        ll a,b;
        int n;
        cin>>a>>b>>n;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            ban_12558.insert(x);
        }
        ok=false;
        for(maxed_12558=1;;maxed_12558++){
            memset(ans_12558,-1, sizeof(ans_12558));
            dfs_12558(0,get_first_12558(a,b),a,b);
            if(ok)
                break;
        }
        cout<<"Case "<<t++<<": "<<a<<"/"<<b<<"=1/"<<ans_12558[0];
        for(int i=1;i<=maxed_12558;i++){
            cout<<"+1/"<<ans_12558[i];
        }
        cout<<endl;
    }
    return 0;
}

/*
5
2 3 0
19 45 0
2 3 1 2
5 121 0
5 121 1 33
*/
