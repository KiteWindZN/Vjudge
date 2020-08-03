//
// Created by 张楠 on 2020/5/3.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
vector<int> nums_120;

void flip_120(int index){
    int i=0;
    int j=index;
    while(i<j){
        int t=nums_120[i];
        nums_120[i]=nums_120[j];
        nums_120[j]=t;
        i++;
        j--;
    }
}

void solve_120(int num_len){
    if(num_len==0)
        return ;
    int max=nums_120[0];
    int choose_index=0;
    for(int i=0;i<num_len;i++){
        if(max<nums_120[i]){
            max=nums_120[i];
            choose_index=i;
        }
    }
    if(choose_index==num_len-1){
        solve_120(num_len-1);
    }else{
        if(choose_index==0){// flip 1
            cout<<nums_120.size()-(num_len-1)<<" ";
            flip_120(num_len-1);
        }else{ // filp 2
            cout<<nums_120.size()-choose_index<<" ";
            cout<<nums_120.size()-(num_len-1)<<" ";
            flip_120(choose_index);
            flip_120(num_len-1);
        }
        solve_120(num_len-1);
    }
}


int main_uva120(){
    string line;
    while(getline(cin,line)){
        nums_120.clear();
        stringstream ss(line);
        int num;
        while(ss>>num)
            nums_120.push_back(num);
        cout<<line<<endl;
        solve_120(nums_120.size());
        cout<<0<<endl;
    }
    return 0;
}