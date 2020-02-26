//
// Created by 张楠 on 2020-02-26.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx_439[]={2,2,-2,-2,-1,1,-1,1};
int dy_439[]={-1,1,-1,1,2,2,-2,-2};
int visited_439[8][8];
int solve_439(int startx,int starty,int endx,int endy){
    queue<int> queue1;
    queue<int> queue2;
    queue1.push(startx);
    queue1.push(starty);
    int ret=0;
    queue2.push(ret);
    visited_439[startx][starty]=1;

    while(queue1.size()>0){
        int x=queue1.front();
        queue1.pop();
        int y=queue1.front();
        queue1.pop();
        ret=queue2.front();
        queue2.pop();

        if(x==endx && y==endy){
            return ret;
        }
        for(int i=0;i<8;i++){
            int tmpx=x+dx_439[i];
            int tmpy=y+dy_439[i];
            if(tmpx>=0&&tmpx<8&&tmpy>=0&&tmpy<8&&visited_439[tmpx][tmpy]==0){

                queue1.push(tmpx);
                queue1.push(tmpy);
                queue2.push(ret+1);
                visited_439[tmpx][tmpy]=1;
            }
        }
    }
    return ret;
}
int main_uva439(){
    string line1;
    string line2;
    while(cin>>line1&&cin>>line2){
        memset(visited_439,0, sizeof(visited_439));
        int startx=line1[0]-'a';
        int starty=line1[1]-'1';

        int endx=line2[0]-'a';
        int endy=line2[1]-'1';
        int stepNum=solve_439(startx,starty,endx,endy);
        cout<<"To get from "<<line1<<" to "<<line2<<" takes "<<stepNum<<" knight moves."<<endl;
    }


    return 0;
}