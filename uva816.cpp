//
// Created by 张楠 on 2020-01-29.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

struct Node{
    int r,c,dir;
    Node(){}
    Node(int r_1,int c_1,int dir_1){
        r=r_1;c=c_1;dir=dir_1;
    }
};

const char* dirs="NESW";
const char* turn="FLR";

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

Node p[10][10][4];
int step[10][10][4][3];
int d[10][10][4];

int r0,c0,dir,r1,c1,r2,c2;

int get_dir(char ch){
    return strchr(dirs,ch)-dirs;
}

int get_turn(char ch){
    return strchr(turn,ch)-turn;
}

Node walk(Node &cur_node,int turn){
    int dir;
    dir=cur_node.dir;

    if(turn==1){
        dir=(dir+3)%4;
    }else if(turn==2){
        dir=(dir+1)%4;
    }
    return Node(cur_node.r+dr[dir],cur_node.c+dc[dir],dir);
}

bool inside(int r,int c){
    if(r>0&& r<=9 && c>0 && c<=9)
        return true;
    return false;
}

bool read_case(){
    char s[99],s2[99];
    if(scanf("%s%d%d%s%d%d",s,&r0,&c0,&s2,&r2,&c2)!=6)
        return false;
    printf("%s\n",s);

    dir= get_dir(s2[0]);
    r1=r0+dr[dir];
    c1=c0+dc[dir];

    memset(step,0, sizeof(step));

    for(;;){
        int r,c;
        scanf("%d",&r);
        if(r==0)
            break;
        scanf("%d",&c);
        while(scanf("%s",s)==1 && s[0]!='*'){
            for(int i=1;i<strlen(s);i++){
                step[r][c][get_dir(s[0])][get_turn(s[i])]=1;
            }
        }
    }
    return true;
}


void print_ans(Node u) {

    vector<Node> nodes;
    for(;;) {
        nodes.push_back(u);
        if(d[u.r][u.c][u.dir] == 0) break;
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back(Node(r0, c0, dir));

    int cnt = 0;
    for(int i = nodes.size()-1; i >= 0; i--) {
        if(cnt % 10 == 0) printf(" ");
        printf(" (%d,%d)", nodes[i].r, nodes[i].c);
        if(++cnt % 10 == 0) printf("\n");
    }
    if(nodes.size() % 10 != 0) printf("\n");
}

void resolve(){
    queue<Node> q;
    memset(d,-1,sizeof(d));
    Node u(r1,c1,dir);
    q.push(u);
    d[r1][c1][dir]=0;
    while(q.size()>0){
        Node tmp_node=q.front();
        q.pop();

        if(tmp_node.r==r2 && tmp_node.c==c2){
            print_ans(tmp_node);
            return;
        }

        for(int i=0;i<3;i++){
            Node v=walk(tmp_node,i);
            if(step[tmp_node.r][tmp_node.c][tmp_node.dir][i] && inside(v.r,v.c)
               && d[v.r][v.c][v.dir]<0){
                d[v.r][v.c][v.dir]=d[tmp_node.r][tmp_node.c][tmp_node.dir]+1;
                p[v.r][v.c][v.dir]=tmp_node;
                q.push(v);
            }
        }

    }
    cout<<"  No Solution Possible"<<endl;

}

int main_uva816(){
    while(read_case()){
        resolve();
    }
    return 0;
}
/*
SAMPLE
3 1 N 2 1
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
3 3 SR *
3 2 WF *
0
*/