//
// Created by 张楠 on 2020/3/31.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
typedef long long LL;

int cnt,sum;
char exp[1500000];
map<LL,int> ID;

void dfs(int l,int r,int depth){
    if(exp[l] == '['){
        int p = 0;
        for(int i = l+1;i <= r;i++){
            if(exp[i] == '[') p++;
            else if(exp[i] == ']') p--;
            if(p==0 && exp[i]==','){
                dfs(l+1,i-1,depth+1);
                dfs(i+1,r-1,depth+1);
            }
        }
    }
    else{
        int weight;
        sscanf(exp+l,"%d",&weight);
        ID[(LL)weight*(1<<depth)]++;
        sum++;
    }
}

int main_lost()
{
    //freopen("input.txt","r",stdin);
    int iCase;
    scanf("%d",&iCase);
    while(iCase--){
        ID.clear();
        cnt = 1,sum = 0;
        scanf("%s",exp);
        dfs(0,strlen(exp)-1,0);
        map<LL,int>::iterator iter;
        int Max = 0;
        for(iter = ID.begin();iter != ID.end();iter++){
            Max = Max > iter->second ? Max : iter->second;
        }
        printf("%d\n",sum-Max);
    }
    return 0;
}