//
// Created by 张楠 on 2019-12-24.
//
/*
#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <map>
#include <cstring>
#include <set>
#include <vector>
#include <sstream>
using namespace std;


#define rep(i,b) for(int i=0;i<(b);i++)
#define foreach(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define FOR for(int j=limit[i];j<limit[i+1];j++)

typedef bool Bit[1505];
int n,m,line_num;
int limit[1505];

string doc[1505];
map<string,Bit> Index;

void update_index(string s,int num){
    string word;
    foreach(t,s)
        if(isalpha(*t)) *t=tolower(*t);
        else
            *t=' ';
    stringstream ss(s);
    while(ss>>word)
        Index[word][num]= true;
}

int main_1597_a(){
    line_num=0;
    cin>>n;
    getchar();
    rep(i,n){
        limit[i]=line_num;
        string line;
        getline(cin,line);
        while(line!="**********"){
            doc[line_num]=line;
            update_index(line,line_num);
            line_num++;
            getline(cin,line);
        }
    }
    limit[n]=line_num;

    cin>>m;
    getchar();
    rep(i,m){
        Bit mark;
        bool *A;
        bool *B;
        string s;
        getline(cin,s);
        if(s[0]=='N'){
            string word=s.substr(4);
            A=Index[word];
            rep(i,n){
                bool flag= true;
                FOR if(A[j]) {
                        flag= false;
                        break;
                    }

                FOR
                    mark[j]= flag;

            }
        }else if(s.find("AND")!=string::npos){
            int p=s.find(" AND ");
            string word1=s.substr(0,p);
            string word2=s.substr(p+5);
            memset(mark, 0, sizeof(mark));
            A=Index[word1];
            B=Index[word2];
            rep(i,n){
                bool hasA=false;
                bool hasB= false;
                FOR if(A[j]) {hasA=true;break;}
                FOR if(B[j]) {hasB= true;break;}

                if(hasA && hasB){
                    FOR
                        mark[j]=(A[j]||B[j]);
                }
            }

        }else if(s.find("OR")!=string::npos){
            int p=s.rfind(" OR ");
            string word1=s.substr(0,p);
            string word2=s.substr(p+4);
            A=Index[word1];
            B=Index[word2];
            rep(i,line_num)
                mark[i]=(A[i]||B[i]);
        }else{
            memcpy(mark,Index[s], sizeof(mark));
        }

        bool has_out=false;
        bool need_out=false;
        rep(i,n){
            if(has_out) need_out= true;
            has_out= false;
            FOR{
                if(mark[j]){
                    if(need_out){
                        cout<<"----------"<<endl;
                        need_out= false;
                    }
                    cout<<doc[j]<<endl;
                    has_out= true;
                }
            }

        }
        if(!(has_out || need_out)){
            cout<<"Sorry, I found nothing."<<endl;
        }
        cout<<"=========="<<endl;



    }
    return 0;
}
*/