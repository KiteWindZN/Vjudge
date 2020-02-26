//
// Created by 张楠 on 2019-11-29.
//

#include <queue>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main_540(){
    int t;
    cin>>t;
    int start=1;
    while (t!=0){
        cout<<"Scenario #"<<start<<endl;
        start++;
        map<int,int> my_map;
        for(int i=0;i<t;i++){
            int num;
            cin>>num;
            for(int j=0;j<num;j++){
                int id;
                cin>>id;
                my_map[id]=i;
            }
        }

        string line;
        cin>>line;
        queue<int> q;
        queue<int> q_team[t];
        while(line[0]!='S'){
            if(line[0]=='E'){
                int nn;
                cin>>nn;
                int team_id=my_map[nn];
                if(q_team[team_id].size()==0){
                    q_team[team_id].push(nn);
                    q.push(team_id);
                }else{
                    q_team[team_id].push(nn);
                }
            }else if(line[0]=='D'){
                int team_id=q.front();
                cout<<q_team[team_id].front()<<endl;
                q_team[team_id].pop();
                if(q_team[team_id].size()==0){
                    q.pop();
                }
            }
            cin>>line;
        }

        cout<<endl;
        cin>>t;
    }
}