//
// Created by 张楠 on 2019-12-04.
//

#include <iostream>
#include <queue>

using namespace std;
int main_10935(){
    int num;
    cin>>num;
    while(num!=0){
        queue<int> q;
        for(int i=1;i<=num;i++){
            q.push(i);
        }
        if(num==1){
            cout<<"Discarded cards:"<<endl;//<- No space here!!!
            cout<<"Remaining card: 1"<<endl;
            cin>>num;
            continue;
        }
        cout<<"Discarded cards: ";
        while(q.size()>2){
            cout<<q.front()<<", ";
            q.pop();
            int tmp=q.front();
            q.pop();
            q.push(tmp);
        }

        cout << q.front() << endl;
        q.pop();
        cout << "Remaining card: " << q.front() << endl;

        cin>>num;
    }
    return 0;
}