//
// Created by 张楠 on 2020/4/18.
//

#include <iostream>
#include <cstring>
using namespace std;

int visited_8q[3][20];
int cur_8q[10];
int cnt_8q=0;
int num_8q=0;

void solve_8q1(int cur){
    if(cur==num_8q){
        cnt_8q++;
        return;
    }
    for(int i=0;i<num_8q;i++){
        int ok=1;
        for(int j=0;j<cur;j++){
            if(cur_8q[j]-j==i-cur || cur_8q[j]+j==i+cur || i==cur_8q[j]){
                ok=0;
                break;
            }
        }
        if(ok==1){
            cur_8q[cur]=i;
            solve_8q1(cur+1);
        }
    }
}

void solve_8q2(int cur){
    if(cur==num_8q){
        cnt_8q++;
        return;
    }
    for(int i=0;i<num_8q;i++){
        if(visited_8q[0][cur+i]==1 || visited_8q[1][i]==1 || visited_8q[2][cur-i+num_8q]==1){
            continue;
        }
        cur_8q[cur]=i;
        visited_8q[0][cur+i]=1;
        visited_8q[1][i]=1;
        visited_8q[2][cur-i+num_8q]=1;
        solve_8q2(cur+1);
        visited_8q[0][cur+i]=0;
        visited_8q[1][i]=0;
        visited_8q[2][cur-i+num_8q]=0;
    }
}
int main_queen(){
    while(cin>>num_8q){
        cnt_8q=0;
        solve_8q1(0);
        cout<<cnt_8q<<endl;
        cnt_8q=0;
        memset(visited_8q,0, sizeof(visited_8q));
        solve_8q2(0);
        cout<<cnt_8q<<endl;
    }
    return 0;
}