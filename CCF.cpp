//
// Created by 张楠 on 2019-11-28.
//

#include <iostream>
using namespace std;
int main_1() {

    int N,M;
    cin>>N>>M;
    int sum=0;
    int choose_index=-1;
    int max=0;
    for(int i=0;i<N;i++){
        int start;
        cin>>start;
        sum+=start;
        int tmp_num=0;
        for(int j=0;j<M;j++){
            int tmp;
            cin>>tmp;
            tmp_num -= tmp;
        }
        sum-=tmp_num;
        if(tmp_num>max){
            max=tmp_num;
            choose_index=i+1;
        }
    }
    cout << sum << " " <<choose_index<< " " << max <<endl;
    return 0;
}