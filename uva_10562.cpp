//
// Created by 张楠 on 2020-01-31.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxN=210;
char buf_1[maxN][maxN];

void read_case_1(){
    memset(buf_1,'#', sizeof(buf_1));
    int i=0;
    for(;;){
        fgets(buf_1[i],maxN,stdin);

        if(buf_1[i][0]=='#')
            break;
        i++;
    }
}

void print_tree(int r,int c){
    printf("%c(",buf_1[r][c]);
    if(buf_1[r+1][c]=='|'){

        int start=c,end=c;
        while(start-1>=0 && buf_1[r+2][start-1]=='-') start--;
        while(end+1<maxN && buf_1[r+2][end+1]=='-') end++;

        for(;start<=end && buf_1[r+3][start]!='\0';start++){
            if(buf_1[r+3][start]!=' ' && buf_1[r+3][start]!='\n' ){
                print_tree(r+3,start);
            }
        }
    }
    printf("%c",')');

}

void solve_10562(){
    if(buf_1[0][0]=='#') {
        printf("%s\n", "()");
        return;
    }

    for(int i=0;i<strlen(buf_1[0]);i++){
        if(buf_1[0][i]!=' '){
            printf("%s","(");
            print_tree(0,i);
            printf("%s\n",")");
            break;
        }
    }
}

int main_10562(){
    int T;
    cin>>T;
    getchar();
    while(T>0){
        read_case_1();
        solve_10562();
        T--;
    }
    return 0;
}
/*
2
   A
   |
--------
B C   D
  |   |
----- -
 E F  G
#
 e
 |
----
f g
#
*/