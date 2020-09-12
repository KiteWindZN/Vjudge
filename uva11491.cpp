//
// Created by 张楠 on 2020/9/12.
//

#include <iostream>
using namespace std;

const int maxd_11491=100000+10;
int A_11491[maxd_11491];

int main_11491(){
    int n,m;
    cin>>n>>m;
    while(n!=0&&m!=0){
        string line;
        cin>>line;
        int p=0;
        for(int i=0;i<n;i++){
            while(m&&p&&A_11491[p-1]<line[i]-'0'){
                m--;
                p--;
            }
            A_11491[p++]=line[i]-'0';
        }
        while(m--)
            p--;
        for(int i=0;i<p;i++){
            cout<<A_11491[i];
        }
        cout<<endl;
        cin>>n>>m;
    }
    return 0;
}