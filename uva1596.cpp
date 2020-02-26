//
// Created by 张楠 on 2019-12-23.
//

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

set<int> digit;

struct Token{

    long long len;
    map<long long,int> vlaue_map;
};

map<string,Token> token_map;


void init(){
    for(int i=0;i<=9;i++){
        digit.insert(i);
    }
}
long long str_long(string str){
    long long value=0;
    for(int i=0;i<str.length();i++){
        value=value*10 + str[i]-'0';
    }
    return value;
}
stack<string> str_split(string str){
    stack<string> res;
    int start=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='['||str[i]==']'){

            string tmp_str=str.substr(start,i-start);
            if(tmp_str.length()>0)
                res.push(tmp_str);
            start=i+1;
        }
    }
    if(str[str.length()-1]!='[' && str[str.length()-1]!=']'){
        res.push(str.substr(start));
    }
    return res;
}


long long is_valid_1(stack<string> &name_stack){
    long long value=0;

    while(name_stack.size()>2){
        string str_1=name_stack.top();
        name_stack.pop();
        string str_2=name_stack.top();
        name_stack.pop();

        if(digit.count(str_1[0]-'0')!=0){
            value=str_long(str_1);
            Token token=token_map[str_2];
            if(value>=token.len || value<0){
                return -1;
            }
            if(token.vlaue_map.count(value)==0){
                return -1;
            }
            value=token.vlaue_map[value];
            name_stack.push(to_string(value));
        }
    }

    if(name_stack.size()==2){
        string str_1=name_stack.top();
        name_stack.pop();
        string str_2=name_stack.top();
        name_stack.push(str_1);
        value=str_long(str_1);

        if(token_map.count(str_2)==0){
            return -1;
        }

        if(token_map[str_2].len<=value || value <0){
            return -1;
        }
        return value;
    }
    return -1;
}

long long is_valid_2(stack<string> name_stack){

    while(name_stack.size()>1){
        string str_1=name_stack.top();
        name_stack.pop();
        string str_2=name_stack.top();
        name_stack.pop();
        long long  value=0;

        int tmp=str_1[0]-'0';
        if(digit.count(tmp)!=0){
            value=str_long(str_1);
            Token token=token_map[str_2];
            if(value>=token.len || value<0){
                return -1;
            }
            if(token.vlaue_map.count(value)==0){
                return -1;
            }
            value=token.vlaue_map[value];
            name_stack.push(to_string(value));
        }
    }

    if(name_stack.size()==1){
        string str=name_stack.top();
        name_stack.pop();
        return str_long(str);
    }
    return -1;
}



int main_1596(){
    string line;
    getline(cin,line);
    init();
    while(line!="."){
        token_map.clear();
        int row_num=1;
        int flag=0;
        while(line!="."){
            if(flag==1){
                getline(cin,line);
                continue;
            }
            int index=line.find("=");
            if(index!=string::npos){
                string str1=line.substr(0,index);
                string str2=line.substr(index+1);
                stack<string> stack_1=str_split(str1);
                stack<string> stack_2=str_split(str2);
                long long res_1=is_valid_1(stack_1);
                long long res_2=is_valid_2(stack_2);
                if(res_1==-1||res_2==-1){
                    cout<<row_num<<endl;
                    flag=1;
                    continue;
                }
                stack_1.pop();
                string str_3=stack_1.top();
                token_map[str_3].vlaue_map[res_1]=res_2;

            }else{

                Token token;
                string str_2="";
                str_2=str_2+line[0];
                string str_1=line.substr(2,line.length()-3);

                long long value=str_long(str_1);

                if(value<0 || token_map.count(str_2)!=0){
                    cout<<row_num<<endl;
                    flag=1;
                    continue;
                }
                token.len=value;
                token_map[str_2]=token;
            }
            getline(cin,line);
            row_num++;
        }
        if(flag==0){
            cout<<0<<endl;
        }
        getline(cin,line);
    }
    return 0;
}