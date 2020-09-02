//
// Created by 张楠 on 2020/9/2.
//

#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int maxd_12174=100000+5;
int songs_12174[maxd_12174];
int n_12174,m_12174;
int count_12174[maxd_12174];
int vis_12174[maxd_12174];

int solve_12174_1(){
    set<int> ss;
    memset(count_12174,-1, sizeof(count_12174));
    for(int i=0;i<m_12174;i++){
        if(count_12174[songs_12174[i]]==-1){
            count_12174[songs_12174[i]]=i;
        }else{
            int start=count_12174[songs_12174[i]];
            int end=i;

            int len=end-start;
            if(len<n_12174){
                int s=start-(n_12174-len)+1;
                // s=max(s,0);
                for(int j=s;j<=start;j++){
                    int nn=(j+n_12174)%n_12174;
                    ss.insert(nn);
                }
                if(ss.size()==n_12174){
                    return 0;
                }
            }
            count_12174[songs_12174[i]]=i;
        }
    }
    return n_12174-ss.size();

}

int main_12174(){
    int T;
    cin>>T;

    while(T--){
        cin>>n_12174>>m_12174;
        for(int i=0;i<m_12174;i++){
            cin>>songs_12174[i];
        }

        int iot=0;

        memset(count_12174,0, sizeof(count_12174));
        for(int i=0;i<n_12174+m_12174;i++){
            if(i<m_12174){
                if(++vis_12174[songs_12174[i]]==1)
                    iot++;
            }
            if(i>=n_12174){
                if(--vis_12174[songs_12174[i-n_12174]]==0)
                    iot--;
            }
            if(min(i,m_12174-1)-max(i- n_12174 +1,0) +1 != iot){
                count_12174[i%n_12174]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n_12174;i++){
            if(count_12174[i]==0){
                ans++;
            }
        }
        cout<<ans<<endl;
        /* int count=solve_12174_1();
         cout<<count<<endl;*/
    }
    return 0;
}
/*

5
4 10
3 4 4 1 3 2 1 2 3 4
6 6
6 5 4 3 2 1
3 5
3 3 1 1 1
7 3
5 7 3
4 7
1 1 3 0 1 4 5

*/
