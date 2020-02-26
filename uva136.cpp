//
// Created by 张楠 on 2019-12-01.
//

#include <queue>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;

int main_136(){
    LL i=1;
    priority_queue<LL,vector<LL>, greater<LL> > q;
    set<LL> s;
    s.insert(1);
    q.push(1);
    for(;;i++){
        LL cur=q.top();
        q.pop();

        if(i==1500){
            cout<<"The 1500'th ugly number is <"<<cur<<">."<<endl;
            return 0;
        }
        if(!s.count(2*cur)) {
            q.push(2 * cur);
            s.insert(2*cur);
        }
        if(!s.count(3*cur)) {
            q.push(3 * cur);
            s.insert(3*cur);
        }
        if(!s.count(5*cur)) {
            q.push(5 * cur);
            s.insert(5*cur);
        }
    }
    return 0;
}
