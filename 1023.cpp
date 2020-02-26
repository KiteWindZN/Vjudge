//
// Created by 张楠 on 2019-11-29.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string get_double(string str){
    string res="";
    int len=str.length();
    int cn=0;
    for(int i=len-1;i>=0;i--){
        int num=(str[i]-'0')*2+cn;
        cn=num/10;
        num=num%10;
        char ch=num+'0';
        res=ch+res;
    }
    if(cn>0){
        char ch=cn+'0';
        res=ch+res;
    }
    return res;
}
int main_1023(){
    string str;
    cin>>str;
    string double_str=get_double(str);
    string str_1=double_str;
    sort(str.begin(),str.end());
    sort(double_str.begin(),double_str.end());
    if(str==double_str){
        cout<<"Yes"<<endl;
    } else {
        cout << "No" << endl;
    }
    cout<<str_1<<endl;
    return 0;

}