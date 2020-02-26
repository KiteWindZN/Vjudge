//
// Created by 张楠 on 2019-12-28.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct matrix{
    int row;
    int cloumn;
    matrix(){}

    matrix(int r,int c){
        row=r;
        cloumn=c;
    }
};


int main_uva442(){
    int n;
    cin>>n;
    map<char,matrix> matrix_map;
    for(int i=0;i<n;i++){
        string name;
        int r,c;
        cin>>name>>r>>c;
        matrix_map[name[0]]=matrix(r,c);
    }
    string line;

    while(cin>>line){
        int sum=0;
        int flag=0;
        stack<matrix> matrix_stack;
        for(int i=0;i<line.length();i++){
            if(isalpha(line[i])){
                matrix_stack.push(matrix_map[line[i]]);
            }else if(line[i]==')'){
                matrix m_2=matrix_stack.top();
                matrix_stack.pop();
                matrix m_1=matrix_stack.top();
                matrix_stack.pop();

                if(m_1.cloumn!=m_2.row){
                    cout<<"error"<<endl;
                    flag=1;
                    break;
                }else{
                    sum+=m_1.row*m_1.cloumn*m_2.cloumn;
                    matrix m_3=matrix(m_1.row,m_2.cloumn);
                    matrix_stack.push(m_3);
                }
            }
        }
        if(flag==1)
            continue;
        if(matrix_stack.size()>1){
            matrix m_2=matrix_stack.top();
            matrix_stack.pop();
            matrix m_1=matrix_stack.top();
            matrix_stack.pop();

            if(m_1.cloumn!=m_2.row){
                cout<<"error"<<endl;
                break;
            }else{
                sum+=m_1.row*m_1.cloumn*m_2.cloumn;
                cout<<sum<<endl;
            }
        }else{
            cout<<sum<<endl;
        }
    }
    return 0;
}