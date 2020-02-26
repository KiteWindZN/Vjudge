//
// Created by 张楠 on 2019-12-29.
//

#include <iostream>
#include <cstring>

using namespace std;

int main_uva679(){
    int N;
    cin>>N;
    while(N>0){
        int D,I;
        cin>>D>>I;
        int k=1;
        for(int i=0;i<D-1;i++){
            if(I%2==1){
                k=2*k;
                I=(I+1)/2;
            }else{
                k=k*2+1;
                I=I/2;
            }
        }
        cout<<k<<endl;

        N--;
    }
    return 0;
}