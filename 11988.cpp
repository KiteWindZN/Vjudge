//
// Created by 张楠 on 2019-12-29.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main_uva11988(){
    char ch;

    int flag=0;
    char s[100005];
    int next[100005];

    while(cin>>s+1){
        memset(next,0,sizeof(next));
        int cur=0;
        int end=0;
        for(int i=1;s[i]!='\0';i++){
            ch=s[i];
            if(ch!='['&& ch!=']'){

                next[i]=next[cur];
                next[cur]=i;

                if(cur==end)
                    end=i;
                cur=i;
            }else{
                if(ch=='['){
                    flag=1;
                    cur=0;
                    //end=cur;
                }else{
                    flag=0;
                    cur=end;
                }
            }
        }


        for(int i=next[0];i!=0;i=next[i]){
            cout<<s[i];
        }
        cout<<endl;
    }

    return 0;
}