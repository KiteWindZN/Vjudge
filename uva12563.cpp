//
// Created by 张楠 on 2020/10/21.
//

#include <iostream>
#include <cstring>
using namespace std;
int n_12563;
int t_12563;
int f_12563[50*180+678+2];
int len_12563[50*180+678+2];
int main_uva12563(){

    int T;
    cin>>T;
    int count=0;
    while(T--){
        count++;
        cin>>n_12563>>t_12563;
        memset(f_12563,0, sizeof(f_12563));
        memset(len_12563,0, sizeof(len_12563));
        for(int i=1;i<=n_12563;i++){
            int len;
            cin>>len;
            for(int j=t_12563-1;j>0;j--){
                if(j>=len){
                    //f_12563[j]=max(f_12563[j],f_12563[j-len]+1);
                    if(f_12563[j-len]+1>f_12563[j]){
                        f_12563[j]=f_12563[j-len]+1;
                        len_12563[j]=len_12563[j-len]+len;
                    }else if(f_12563[j-len]+1==f_12563[j]){
                        len_12563[j]=max(len_12563[j],len_12563[j-len]+len);
                    }
                }
            }

        }
        int ans=len_12563[t_12563-1];

        ans+=678;
        cout<<"Case "<<count<<": ";
        cout<<f_12563[t_12563-1]+1<<" "<<ans<<endl;
    }
    return 0;
}

/*
2
10 10
1 1 1 1 1 1 1 1 1 1
11 100
10 10 10 10 10 15 15 15 15 15 20

*/
