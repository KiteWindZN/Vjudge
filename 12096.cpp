//
// Created by 张楠 on 2019-11-28.
//

#include <set>
#include <vector>
#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef set<int> Set;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

map<Set,int> IDcache;
vector<Set> Setcache;

int ID(Set x){
    if(IDcache.find(x)!=IDcache.end()){
        return IDcache[x];
    }
    Setcache.push_back(x);
    IDcache[x]=Setcache.size()-1;
    return IDcache[x];
}

int main_10296(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        stack<int> s;
        IDcache.clear();
        Setcache.clear();
        for(int j=0;j<num;j++){
            string p;
            cin>>p;
            if(p[0]=='P'){
                s.push(ID(Set()));
            }else if(p[0]=='D'){
                s.push(s.top());
            }else{
                Set x1=Setcache[s.top()];
                s.pop();
                Set x2=Setcache[s.top()];
                s.pop();
                Set x;
                if(p[0]=='A'){
                    x=x2;
                    x.insert(ID(x1));
                }else if(p[0]=='U'){
                    set_union(ALL(x1),ALL(x2),INS(x));
                }else if(p[0]=='I'){
                    set_intersection(ALL(x1),ALL(x2),INS(x));
                }
                s.push(ID(x));
            }
            cout<<Setcache[s.top()].size()<<endl;
        }
        cout<<"***"<<endl;
    }
    return 0;
}