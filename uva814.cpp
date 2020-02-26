//
// Created by 张楠 on 2019-12-04.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

set<string> address;
void process_mat(string sender,string send_mat,vector<string> data,map<string,vector<string>> mat_map,vector<string> mat){
    for(int i=0;i<mat.size();i++){
        string reciver_mat=mat[i];
        cout<<"Connection between "<<send_mat<<" and "<<mat[i]<<endl;
        cout<<"     HELO "<<send_mat<<endl;
        cout<<"     250"<<endl;
        cout<<"     MAIL FROM:<"+sender<<"@"<<send_mat<<">"<<endl;
        cout<<"     250"<<endl;
        int flag=0;
        for(int j=0;j<mat_map[reciver_mat].size();j++){
            string reciver=mat_map[reciver_mat][j]+"@"+reciver_mat;
            cout<<"     RCPT TO:<"<<reciver<<">"<<endl;
            if(address.count(reciver)){
                flag=1;
                cout<<"     250"<<endl;
            } else
                cout<<"     550"<<endl;
        }
        if(flag==1){
            cout<<"     DATA"<<endl<<"     354"<<endl;
            for(int j=0;j<data.size();j++){
                cout<<"     "<<data[j]<<endl;
            }
            cout<<"     ."<<endl;
            cout<<"     250"<<endl;
        }
        cout<<"     QUIT"<<endl<<"     221"<<endl;
    }
}


int main_814(){

    string line;
    cin>>line;
    while(line!="*"){
        string mat;
        cin>>mat;
        int num;
        cin>>num;
        for(int i=0;i<num;i++){
            string user;
            cin>>user;
            address.insert(user+"@"+mat);
        }
        cin>>line;
    }
    cin>>line;
    while(line!="*"){
        vector<string> data;

        string user1,mat1;
        int k=line.find('@');
        user1=line.substr(0,k);
        mat1=line.substr(k+1);

        cin>>line;
        map<string,vector<string>> reciver;
        vector<string> mat;
        set<string> visited;
        while(line!="*"){
            string user2,mat2;
            int k_2=line.find('@');
            user2=line.substr(0,k_2);
            mat2=line.substr(k_2+1);
            if(visited.count(line)==0){
                visited.insert(line);
            } else {
                cin>>line;
                continue;
            }
            if(reciver.count(mat2)==0)
                mat.push_back(mat2);
            reciver[mat2].push_back(user2);

            cin>>line;
        }
        getchar();
        getline(cin,line);
        while(line[0]!='*'){
            data.push_back(line);
            getline(cin,line);
        }

        process_mat(user1,mat1,data,reciver,mat);
        cin>>line;
    }
    return 0;
}