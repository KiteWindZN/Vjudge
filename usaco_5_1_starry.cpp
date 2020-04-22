//
// Created by 张楠 on 2020/4/22.
//

/*
ID: 15605181
LANG: C++
TASK: starry
*/

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int max_5_1=101;

struct Point_5_1{
    int x,y;
    Point_5_1(int x=0,int y=0):x(x),y(y){};

    bool operator <(const Point_5_1 &rh) const{
        return x<rh.x || (x==rh.x && y<rh.y);
    }
};
typedef set<Point_5_1> Polyo;
map<Polyo,char> polyo_map;
int graph_5_1[max_5_1][max_5_1];
char res_5_1[max_5_1][max_5_1];
Polyo normalize_5(Polyo p){
    Polyo p2;
    int minX=max_5_1,minY=max_5_1;
    for(Point_5_1 point:p){
        minX=min(minX,point.x);
        minY=min(minY,point.y);
    }
    for(Point_5_1 point:p){
        p2.insert(Point_5_1(point.x-minX,point.y-minY));
    }
    return p2;
}
Polyo rotate_5(Polyo p){
    Polyo p2;
    for(Point_5_1 point:p){
        p2.insert(Point_5_1(point.y,-point.x));
    }
    return normalize_5(p2);
}
Polyo flip_5(Polyo p){
    Polyo p2;
    for(Point_5_1 point:p){
        p2.insert(Point_5_1(point.x,-point.y));
    }
    return p2;
}
int visit_5_1[max_5_1][max_5_1];
int dx_5_1[]={-1,-1,-1,0,0,1,1,1};
int dy_5_1[]={-1,0,1,-1,1,-1,0,1};
int w_5_1,h_5_1;
int count_5_1=0;

Polyo findPolyo(int x,int y){
    Polyo p;
    visit_5_1[x][y]=1;
    queue<Point_5_1> que;
    que.push(Point_5_1(x,y));
    while(que.size()>0){
        Point_5_1 tmpPoint=que.front();
        que.pop();
        p.insert(tmpPoint);
        for(int i=0;i<8;i++){
            int tmpX=tmpPoint.x+dx_5_1[i];
            int tmpY=tmpPoint.y+dy_5_1[i];
            if(tmpX<0||tmpX>=h_5_1)
                continue;
            if(tmpY<0||tmpY>=w_5_1)
                continue;
            if(graph_5_1[tmpX][tmpY]==1 && visit_5_1[tmpX][tmpY]==0){
                que.push(Point_5_1(tmpX,tmpY));
                visit_5_1[tmpX][tmpY]=1;
            }
        }
    }

    return p;
}

void color_res_5_1(Polyo p){
    Polyo p2=p;

    for(int i=0;i<4;i++){
        p2=rotate_5(p2);
        if(polyo_map.count(p2)){
            char ch=polyo_map[p2];
            for(Point_5_1 point:p){
                res_5_1[point.x][point.y]=ch;
            }
            return;
        }
    }
    p2=flip_5(p2);
    for(int i=0;i<4;i++){
        p2=rotate_5(p2);
        if(polyo_map.count(p2)){
            char ch=polyo_map[p2];
            for(Point_5_1 point:p){
                res_5_1[point.x][point.y]=ch;
            }
            return;
        }
    }
    char ch=(char)(count_5_1+'a');
    count_5_1++;
    for(Point_5_1 point:p){
        res_5_1[point.x][point.y]=ch;
    }
    p=normalize_5(p);
    polyo_map[p]=ch;
}

void solve_5_1(){
    for(int i=0;i<h_5_1;i++){
        for(int j=0;j<w_5_1;j++){
            if(visit_5_1[i][j]==1)
                continue;
            if(graph_5_1[i][j]==0)
                continue;
            Polyo p=findPolyo(i,j);
            color_res_5_1(p);
        }
    }
}

int main_usaco_5_1_starry(){
    fstream fin("starry.in",ios::in);
    fstream fout("starry.out",ios::out);

    memset(visit_5_1,0, sizeof(visit_5_1));
    memset(res_5_1,'0', sizeof(res_5_1));
    fin>>w_5_1>>h_5_1;
    string line;
    for(int i=0;i<h_5_1;i++){
        fin>>line;
        for(int j=0;j<w_5_1;j++){
            graph_5_1[i][j]=line[j]-'0';
        }
    }
    solve_5_1();
    for(int i=0;i<h_5_1;i++){
        for(int j=0;j<w_5_1;j++){
            fout<<res_5_1[i][j];
        }
        fout<<endl;
    }
    fout.close();
    return 0;
}