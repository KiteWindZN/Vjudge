//
// Created by 张楠 on 2020/4/25.
//

#include <iostream>
#include <cstring>
using namespace std;

const int maxn_1603=5;
const int max_1603=100;
int n_1603,s_1603;
int maxd_1603;
int fullsize_1603[max_1603];
int contain_1603[max_1603][max_1603];
int size_1603[max_1603];
char group_1603[max_1603];

int matchrow_1603(int x,int y){
    return x*n_1603*2+x+y;
}

int matchcol_1603(int x,int y){
    return x*n_1603*2+x+y+n_1603;
}

void init_1603(){
    int k;
    cin>>k;
    memset(fullsize_1603,0,sizeof(fullsize_1603));
    memset(size_1603,0, sizeof(size_1603));
    memset(group_1603,1,sizeof(group_1603));
    memset(contain_1603,0, sizeof(contain_1603));

    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        group_1603[t-1]=0;
    }
    s_1603=0;
    for(int i=1;i<=n_1603;i++){
        for(int j=0;j<=n_1603-i;j++){
            for(int k=0;k<=n_1603-i;k++){
                size_1603[s_1603]=0;
                fullsize_1603[s_1603]=i*4;
                for(int h=0;h<i;h++){
                    int a=matchrow_1603(j,k+h);
                    int b=matchrow_1603(j+i,k+h);
                    int c=matchcol_1603(j+h,k);
                    int d=matchcol_1603(j+h,k+i);
                    contain_1603[s_1603][a]=1;
                    contain_1603[s_1603][b]=1;
                    contain_1603[s_1603][c]=1;
                    contain_1603[s_1603][d]=1;
                    size_1603[s_1603]+=group_1603[a]+group_1603[b]+group_1603[c]+group_1603[d];
                }
                s_1603++;
            }
        }
    }
}

int is_end_1603(){
    for(int i=0;i<s_1603;i++)
        if(size_1603[i]==fullsize_1603[i])
            return i;
    return -1;
}

bool solve_1603(int cur){
    int small=is_end_1603();
    if(small==-1)
        return true;
    if(cur>=maxd_1603)
        return false;

    int full=2*n_1603*(n_1603+1);
    int i=small;
    for(int j=0;j<full;j++){
        if(contain_1603[i][j]==1){
            for(int k=0;k<full;k++){
                if(contain_1603[k][j]==1) {
                    size_1603[k]--;
                }
            }
            if(solve_1603(cur+1)) return true;
            for(int k=0;k<full;k++){
                if(contain_1603[k][j]==1) {
                    size_1603[k]++;
                }
            }
        }
    }
    return false;
}

int main_uva1603(){
    int T;
    cin>>T;
    while(T--){
        cin>>n_1603;
        init_1603();
        for(maxd_1603=1;;maxd_1603++)
            if(solve_1603(0)){
                cout<<maxd_1603<<endl;
                break;
            }

    }
    return 0;
}