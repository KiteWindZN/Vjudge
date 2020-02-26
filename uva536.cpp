//
// Created by 张楠 on 2020-02-17.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> myStack;
void solve_536(string pre_str,int start1,int end1,string mid_str,int start2,int end2){
    char ch=pre_str[start1];

    if(start1>end1)
        return ;
    myStack.push(ch);
    int i=start2;
    for(;i<end2;i++){
        if(mid_str[i]==ch)
            break;
    }

    int len1=i-start2-1;
    int len2=end2-i-1;

    int start3=start1+1;
    int end3=start3+len1;
    int start4=start2;
    int end4=i-1;

    int start5=end3+1;
    int end5=end1;
    int start6=i+1;
    int end6=end2;

    solve_536(pre_str,start5,end5,mid_str,start6,end6);
    solve_536(pre_str,start3,end3,mid_str,start4,end4);
}

void print_stack(){
    while(myStack.size()>0){
        char ch=myStack.top();
        cout<<ch;
        myStack.pop();
    }
    cout<<endl;
}

int main_uva536(){
    string pre_str,mid_str;
    while(cin>>pre_str>>mid_str){
        int len=pre_str.length()-1;
        solve_536(pre_str,0,len,mid_str,0,len);
        print_stack();
    }
    return 0;
}
/*
DBACEGF ABCDEFG
BCAD CBAD
 */