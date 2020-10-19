//
// Created by 张楠 on 2020/10/15.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxd_1153=100000+10;
struct worker_1153{
    int cost, deadline;
    worker_1153(int c,int d):cost(c),deadline(d){};
    worker_1153(){};
    bool operator < (const worker_1153 & a){
        if(deadline==a.deadline)
            return cost<a.cost;
        return deadline<a.deadline;
    }
} worker1153[maxd_1153];
int main_uva1153(){

    int T;
    cin>>T;
    bool flag= false;
    while(T--){
        if(flag== true)
            cout<<endl;
        flag=true;
        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>worker1153[i].cost>>worker1153[i].deadline;
        }

        sort(worker1153,worker1153+n);
        priority_queue<int> que;
        int ans=0,pos=0;
        for(int i=0;i<n;i++){

            if(pos+worker1153[i].cost<=worker1153[i].deadline){
                que.push(worker1153[i].cost);
                ans++;
                continue;
            }
            if(!que.empty()){
                int cost=que.top();
                if(cost>worker1153[i].cost&& pos-cost+worker1153[i].cost<=worker1153[i].deadline){
                    que.pop();
                    que.push(worker1153[i].cost);
                    pos=pos-cost+worker1153[i].cost;
                }
            }
        }
        cout<<ans;
    }
}