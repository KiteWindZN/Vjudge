//
// Created by 张楠 on 2019-12-05.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main_1594(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        vector<int> q;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            q.push_back(tmp);
        }
        int tmp;

        int flag=0;
        for(int h=0;h<1000;h++){
            flag=0;
            int start=q[0];
            for(int j=0;j<n-1;j++){
                int tmp_1=q[j];

                int tmp_2=q[j+1];
                tmp=abs(tmp_1-tmp_2);
                q[j]=tmp;
                if(tmp!=0){
                    flag=1;
                }
            }
            q[n-1]=abs(q[n-1]-start);
            if(q[n-1]!=0){
                flag=1;
            }
            if(flag==0){
                cout<<"ZERO"<<endl;
                break;
            }
        }
        if(flag==1)
            cout<<"LOOP"<<endl;
    }
    return 0;
}