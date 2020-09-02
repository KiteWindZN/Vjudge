//
// Created by 张楠 on 2020/9/1.
//

#include <iostream>
#include <cstring>
using namespace std;
const int maxd_714=505;

int main_uva714(){
    long long T,n,m,x,sum,p[maxd_714],mid;
    cin>>T;
    while(T--){
        sum=0;
        x=0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>p[i];
            sum+=p[i];
        }
        while(x<sum){
            mid=(x+sum)/2;
            long long temp=0;
            long long k=1;
            for(int i=0;i<n;i++){
                temp+=p[i];
                if(p[i]>mid){
                    k=m+1;
                    break;
                }
                if(temp>=mid){
                    temp=p[i];
                    k++;
                    if(k>m)
                        break;
                }
            }
            if(k>m){
                x=mid+1;
            }else{
                sum=mid;
            }
        }

        long long temp1=0,temp2=0,flag[n];
        memset(flag,0, sizeof(flag));
        for(int i=n-1;i>=0;i--){
            temp1+=p[i];
            if(temp2<m-1&&(temp1>mid || i<m-1-temp2)){
                temp2++;
                temp1=p[i];
                flag[i]=1;
            }
        }

        for(int i=0;i<n;i++){
            cout<<p[i];
            if(i!=n-1){
                cout<<" ";
            }
            if(flag[i]==1)
                cout<<"/ ";
        }
        cout<<endl;

    }
    return 0;
}

/*
2
9 3
100 200 300 400 500 600 700 800 900
5 4
100 100 100 100 100

 */
