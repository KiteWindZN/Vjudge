//
// Created by 张楠 on 2020/4/28.
//

/*
ID: 15605181
LANG: C++
TASK: snail
*/
#include <fstream>
#include <cstring>
using namespace std;
const int max_snail=121;
int visited_snail[max_snail][max_snail];
char graph_snail[max_snail][max_snail];
int N_snail;
int ans_snail=0;

void solve_snail(int cur,int row,int col,int direct){
    if( visited_snail[row][col]==1){
        if(cur>ans_snail){
            ans_snail=cur;
        }
        return;
    }
    if(direct==0){
        if(row==-1||graph_snail[row][col]=='#'){//转弯
            row++;
            int flag=0;
            if(col<N_snail-1){//右转
                if(graph_snail[row][col+1]!='#'){
                    solve_snail(cur,row,col+1,2);
                    flag=1;
                }
            }
            if(col>0){//左转
                if(graph_snail[row][col-1]!='#'){
                    solve_snail(cur,row,col-1,3);
                    flag=1;
                }
            }
            if(flag==0){
                if(cur>ans_snail){
                    ans_snail=cur;
                }
            }
        }else {
            visited_snail[row][col]=1;
            row--;
            solve_snail(cur+1,row,col,direct);
            row++;
            visited_snail[row][col]=0;
        }
    }else if(direct==1){
        if(row==N_snail || graph_snail[row][col]=='#'){
            row--;
            int flag=0;
            if(col<N_snail-1){//右转
                if(graph_snail[row][col+1]!='#'){
                    solve_snail(cur,row,col+1,2);
                    flag=1;
                }
            }
            if(col>0){//左转
                if(graph_snail[row][col-1]!='#'){
                    solve_snail(cur,row,col-1,3);
                    flag=1;
                }
            }
            if(flag==0){
                if(cur>ans_snail){
                    ans_snail=cur;
                }
            }
        }else {
            visited_snail[row][col]=1;
            row++;
            solve_snail(cur+1,row,col,direct);
            row--;
            visited_snail[row][col]=0;
        }
    }else if(direct==2){
        if(col==N_snail || graph_snail[row][col]=='#'){
            col--;
            int flag=0;
            if(row<N_snail-1){
                if(graph_snail[row+1][col]!='#'){
                    solve_snail(cur,row+1,col,1);
                    flag=1;
                }

            }
            if(row>0){
                if(graph_snail[row-1][col]!='#'){
                    solve_snail(cur,row-1,col,0);
                    flag=1;
                }
            }
            if(flag==0){
                if(cur>ans_snail){
                    ans_snail=cur;
                }
            }
        }else{
            visited_snail[row][col]=1;
            col++;
            solve_snail(cur+1,row,col,direct);
            col--;
            visited_snail[row][col]=0;
        }
    }else {
        if(col==-1 || graph_snail[row][col]=='#'){
            col++;
            int flag=0;
            if(row<N_snail-1){
                if(graph_snail[row+1][col]!='#'){
                    solve_snail(cur,row+1,col,1);
                    flag=1;
                }
            }
            if(row>0){
                if(graph_snail[row-1][col]!='#'){
                    solve_snail(cur,row-1,col,0);
                    flag=1;
                }
            }
            if(flag==0){
                if(cur>ans_snail){
                    ans_snail=cur;
                }
            }
        }else {
            visited_snail[row][col]=1;
            col--;
            solve_snail(cur+1,row,col,direct);
            col++;
            visited_snail[row][col]=0;
        }
    }
}

int main_5_2_snail(){
    fstream f_in("snail.in",ios::in);
    fstream f_out("snail.out",ios::out);
    memset(graph_snail,'-', sizeof(graph_snail));
    memset(visited_snail,0, sizeof(visited_snail));
    int tmpN;
    f_in>> N_snail>>tmpN;
    for(int i=0;i<tmpN;i++){
        string line;
        f_in>>line;
        char ch=line[0];
        int row=line[1]-'0';
        for(int i=2;i<line.length();i++){
            row=row*10+line[i]-'0';
        }
        int col=ch-'A';
        graph_snail[row-1][col]='#';
    }
    solve_snail(0,0,0,2);
    solve_snail(0,0,0,1);
    f_out<<ans_snail<<endl;
    f_out.close();
    return 0;
}