//
// Created by 张楠 on 2020/8/2.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>;
using namespace std;
const int max_1152=4005;
int A_1152[max_1152];
int B_1152[max_1152];
int C_1152[max_1152];
int D_1152[max_1152];
int T_1152;



int main_1152(){
    cin>>T_1152;
    long a,b,c,d;
    int n;
    while(T_1152>0){
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>A_1152[i]>>B_1152[i]>>C_1152[i]>>D_1152[i];
        }
        unordered_map<int, int> map1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                map1[A_1152[i]+B_1152[j]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tmp=-C_1152[i]-D_1152[j];
                count+=map1[tmp];
            }
        }
        cout<<count<<endl;
        if(T_1152>1)
            cout<<endl;
        T_1152--;
    }
    return  0;
}

