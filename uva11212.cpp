//
// Created by 张楠 on 2020/4/19.
//

#include <iostream>
#include <cstring>
using namespace std;

const int max_11212=9;
int n_11212,a_11212[max_11212];
int maxd_11212;
const int intsz= sizeof(int);
const int asz= sizeof(a_11212);

bool End_11212(){
    for(int i=1;i<n_11212;i++){
        if(a_11212[i]<a_11212[i-1])
            return false;
    }
    return true;
}

int h_11212(){
    int cnt=0;
    for(int i=1;i<n_11212;i++){
        if(a_11212[i]!=a_11212[i-1]+1)
            cnt++;
    }
    return cnt;
}

bool dfs_11212(int d){
    if(3*d+h_11212()>3*maxd_11212)
        return false;
    if(End_11212())
        return true;
    int old[max_11212];
    memcpy(old,a_11212,asz);
    int b[max_11212];
    for(int i=0;i<n_11212;i++)
        if(i==0 || old[i]!=old[i-1]+1){
            for(int j=i;j<n_11212;j++){
                while (j+1 < n_11212 && old[j+1] == old[j]+1)
                    j++;
                memcpy(b,old+i,(j-i+1)*intsz);
                for(int k=j+1;k<n_11212;k++){
                    while(k+1 <n_11212 && old[k+1]==old[k]+1)
                        k++;
                    memcpy(a_11212+i,a_11212+j+1,intsz*(k-j));
                    memcpy(a_11212+k-j+i,b,(j-i+1)*intsz);
                    if(dfs_11212(d+1))
                        return true;
                    memcpy(a_11212,old, asz);
                }
            }
        }
    return false;
}

int solve_11212(){
    if(End_11212())
        return 0;
    for(maxd_11212=1;maxd_11212<5;maxd_11212++){
        if(dfs_11212(0))
            return maxd_11212;
    }
    return 5;
}

int main_uva11212(){
    int Cas=0;
    while(~scanf("%d",&n_11212) && n_11212){
        for(int i=0;i<n_11212;i++){
            scanf("%d",a_11212+i);
        }
        int ans=solve_11212();
        cout<<"Case "<<++Cas<<": "<<ans<<endl;
    }
    return 0;
}

