//
// Created by 张楠 on 2020-01-29.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int words_edge[26][26];
int in[26];
int out[26];
void solve_1(int choose_index){
    for(int i=0;i<26;i++){
        if(words_edge[choose_index][i]>0){
            words_edge[choose_index][i]--;
            solve_1(i);
        }
    }
}

bool solve_2(){
    int a,b;
    a=0;
    b=0;
    for(int i=0;i<26;i++){
        if(in[i]==out[i])
            continue;
        if(in[i]>out[i] ){
            if(in[i]-out[i]==1){
                a++;
            }else
                return false;
        }else{
            if(out[i]-in[i]==1){
                b++;
            } else
                return false;
        }
    }
    if((a==1 && b==1) ||(a==0 && b==0))
        return true;
    return false;
}
int main_uva_10129(){
    int T;
    cin>>T;
    int u,v;
    int n;
    string str;
    while(T>0){
        memset(words_edge,0, sizeof(words_edge));
        memset(in,0, sizeof(in));
        memset(out,0, sizeof(out));

        cin>>n;
        for(int i=0;i<n;i++){
            cin>>str;
            u=str[0]-'a';
            v=str[str.length()-1]-'a';

            words_edge[u][v]++;
            in[v]++;
            out[u]++;
            //words_edge[v]++;
        }

        if(n==1){
            cout<<"Ordering is possible."<<endl;
            T--;
            continue;
        }
        int count=0;
        int choose_index=u;

        for(int i=0;i<26;i++){
            if((in[i]+out[i])%2==1){
                count++;
                if(out[i]-in[i]==1){
                    choose_index=i;
                }
            }
        }


        if(count!=0 && count!=2){
            cout<<"The door cannot be opened."<<endl;
            T--;
            continue;
        }


        count=0;
        solve_1(choose_index);
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(words_edge[i][j]>0){
                    count=1;
                    break;
                }
            }
        }

        if(count==0){
            if(solve_2())
                cout<<"Ordering is possible."<<endl;
            else
                cout<<"The door cannot be opened."<<endl;
        } else
            cout<<"The door cannot be opened."<<endl;

        T--;
    }
    return 0;
}