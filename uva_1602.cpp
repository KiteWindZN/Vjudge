//
// Created by 张楠 on 2020/4/22.
//

#include <iostream>
#include <set>
#include <algorithm>


using namespace std;

const int max_1602=10;
int ans_1602[max_1602+1][max_1602+1][max_1602+1];
int w_1602,h_1602;
int n_1602;

struct Point_1602{
    int x, y;
    Point_1602(int x=0,int y=0):x(x),y(y){}
    bool operator <(const Point_1602 &rh) const{
        return x<rh.x ||(x==rh.x && y<rh.y);
    }
};

typedef set<Point_1602> Polyomino;

#define FOR_CELL(c,p) for(Polyomino::const_iterator c=(p).begin();c!=(p).end();c++)

Polyomino normalize(Polyomino p){
    int minX=p.begin()->x;
    int minY=p.begin()->y;
    FOR_CELL(c,p){
        minX=min(minX,c->x);
        minY=min(minY,c->y);
    }
    Polyomino p2;
    FOR_CELL(c,p){
        p2.insert(Point_1602(c->x-minX,c->y-minY));
    }
    return p2;
}

Polyomino rotate(Polyomino p){
    Polyomino p2;
    FOR_CELL(c,p){
        p2.insert(Point_1602(c->y,-c->x));
    }
    return normalize(p2);
}

Polyomino flip(Polyomino p){
    Polyomino p2;
    FOR_CELL(c,p){
        p2.insert(Point_1602(c->x,-c->y));
    }
    return normalize(p2);
}

const int dx_1602[]={-1,1,0,0};
const int dy_1602[]={0,0,1,-1};

set<Polyomino> poly[max_1602+1];

void check_polyomino(const Polyomino &p0,const Point_1602 c){
    Polyomino p=p0;
    p.insert(c);
    p=normalize(p);

    int n=p.size();
    for(int i=0;i<4;i++){
        if(poly[n].count(p)!=0){
            return ;
        }
        p = rotate(p);
    }
    p=flip(p);
    for(int i=0;i<4;i++){
        if(poly[n].count(p)!=0){
            return ;
        }
        p=rotate(p);
    }
    poly[n].insert(p);
}

void generate_poly(){
    Point_1602 p0=Point_1602(0,0);
    Polyomino s;
    s.insert(p0);
    poly[1].insert(s);
    for(int i=2;i<=max_1602;i++){
        for(set<Polyomino>::iterator p=poly[i-1].begin();p!=poly[i-1].end();p++){
            FOR_CELL(c,*p){
                for(int dir=0;dir<4;dir++){
                    Point_1602 tmpP=Point_1602(c->x+dx_1602[dir],c->y+dy_1602[dir]);
                    if(p->count(tmpP)==0)
                        check_polyomino(*p,tmpP);
                }
            }
        }

    }

    for(int i=1;i<=max_1602;i++){
        for(int w=1;w<=max_1602;w++){
            for(int h=1;h<=max_1602;h++){
                int cnt=0;
                for(set<Polyomino>::iterator p=poly[i].begin();p!=poly[i].end();p++){
                    int maxX=0;
                    int maxY=0;
                    FOR_CELL(c,*p){
                        maxX=max(maxX,c->x);
                        maxY=max(maxY,c->y);
                    }
                    if(min(maxX,maxY)<min(w,h) && max(maxX,maxY)<max(w,h))
                        cnt++;
                }
                ans_1602[i][w][h]=cnt;
            }
        }

    }
}

int main_1602(){
    generate_poly();
    while(cin>>n_1602>>w_1602>>h_1602){
        cout<<ans_1602[n_1602][w_1602][h_1602]<<endl;
    }
    return 0;
}