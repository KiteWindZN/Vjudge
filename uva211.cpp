//
// Created by 张楠 on 2020/7/30.
//

#include <iostream>
#include <cstring>
#include <map>
#include <sstream>
using namespace std;
int graph_211[7][8];
int res_211[7][8];
int visited_211[29];
int visited_graph[7][8];
int dx_211[]={0,0,-1,1};
int dy_211[]={-1,1,0,0};
struct Point_211{
    int x;
    int y;
    Point_211(int x,int y){
        this->x=x;
        this->y=y;
    }
};
map<Point_211,int> pips_211;
void init(){
    int count=1;
    for(int i=0;i<=6;i++){
        for(int j=i;j<=6;j++){
            pips_211[Point_211(i,j)]=count;
            pips_211[Point_211(j,i)]=count;
            count++;
        }
    }
}

Point_211 get_next_211(int x,int y){
    while(x<7){
        while(y<8){
            if(visited_graph[x][y]==0)
                return Point_211(x,y);
            y++;
        }
        x++;
        y=0;
    }
    return Point_211(-1,-1);
}

void printRes(){
    for(int i=0;i<7;i++){
        cout<<"  ";
        if(res_211[i][0]<10)
            cout<<" ";
        cout<<res_211[i][0];
        for(int j=1;j<8;j++){
            cout<<"  ";
            if(res_211[i][j]<10)
                cout<<" ";
            cout<<res_211[i][j];
        }
        cout<<endl;
    }
}

void solve_211(int x,int y){

    for(int i=0;i<4;i++){
        int tx=x+dx_211[i];
        int ty=y+dy_211[i];
        if(visited_graph[tx][ty]==1)
            continue;
        int num1=graph_211[x][y];
        int num2=graph_211[tx][ty];
        Point_211 p1=Point_211(num1,num2);
        Point_211 p2=Point_211(num2,num1);
        if(pips_211.count(p2)&&visited_211[pips_211[p2]]==0){
            res_211[x][y]=pips_211[p2];
            res_211[tx][ty]=pips_211[p2];
            visited_211[pips_211[p2]]=1;
            visited_graph[x][y]=1;
            visited_graph[tx][ty]=1;

            Point_211 nextP=get_next_211(x,y);
            if(nextP.x==-1){
                printRes();
                visited_211[pips_211[p2]]=0;
                visited_graph[x][y]=0;
                visited_graph[tx][ty]=0;
                return;
            }
            solve_211(nextP.x,nextP.y);
            visited_211[pips_211[p2]]=0;
            visited_graph[x][y]=0;
            visited_graph[tx][ty]=0;
        }
    }
}


int main()_uva211{
    string line;
    while(getline(cin,line)){
        memset(visited_211,0, sizeof(visited_211));
        int x=0;
        while(x<7){
            stringstream ss(line);
            int y=0;
            while(y<8)ss>>graph_211[x][y++];
            x++;
            if(x<7)
                getline(cin,line);
        }
    }
    return 0;
}