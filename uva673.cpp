//
// Created by 张楠 on 2020-02-17.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool solve_673(string str){
    int len=str.length();
    stack<char> stk;
    for(int i=0;i<len;i++){
        if(str[i]=='('||str[i]=='['){
            stk.push(str[i]);
        }else{
            if(stk.size()==0)
                return false;
            char ch=stk.top();
            stk.pop();
            if(ch=='('){
                if(str[i]==']')
                    return false;
            }else{
                if(str[i]==')')
                    return false;
            }
        }
    }
    if(stk.size()>0)
        return false;
    return true;
}

int main_uva673(){
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);
        if(solve_673(str)){
            cout<<"Yes"<<endl;
        } else
            cout<<"No"<<endl;
    }
    return 0;
}