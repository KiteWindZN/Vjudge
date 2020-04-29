//
// Created by 张楠 on 2020/4/30.
//

/*
ID: 15605181
LANG: C++
TASK: milk4
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int Q_milk4=0;
vector<int> res_milk4;
vector<int> pail_milk4;
int p_milk4;
int max_milk4=0;
bool dfs_milk4(vector<int> curV,int curQ,int curDI){
    if(curQ==0){
        if(curV.size()<res_milk4.size()){
            res_milk4=curV;
        }else if(curV.size()==res_milk4.size()){
            if(curV<res_milk4){
                res_milk4=curV;
            }
        }
        return true;
    }
    if(curDI==0){
        if(curQ%curV[curDI]==0){
            if(curV.size()<res_milk4.size()){
                res_milk4=curV;
            }else if(curV.size()==res_milk4.size()){
                if(curV<res_milk4){
                    res_milk4=curV;
                }
            }
            return true;
        }
        return false;
    }
    int count=curQ/curV[curDI];
    for(int i=1;i<=count;i++){
        curQ-=(i*curV[curDI]);
        if(curDI>0 && dfs_milk4(curV,curQ,curDI-1))
            return true;
        curQ+=(i*curV[curDI]);
    }
    return false;
}

bool solve_milk42(vector<int> curV,int curI){
    if(curV.size()<max_milk4){
        for(int i=curI;i<pail_milk4.size();i++){
            curV.push_back(pail_milk4[i]);
            if(solve_milk42(curV,curI+1)){
                return true;
            }
            curV.erase(curV.begin()+curV.size()-1);
        }
    }else{
        if(dfs_milk4(curV,Q_milk4,curV.size()-1))
            return true;
    }
    return false;
}
/*
void solve_milk4(vector<int> curSet,int curI,int curQ){
    for(int i=curI;i<pail_milk4.size();i++){
        curSet.push_back(pail_milk4[i]);
        if(curSet.size()>=res_milk4.size()){
            curSet.erase(curSet.begin()+curSet.size()-1);
            return;
        }
        if(dfs_milk4(curSet,curQ,curSet.size()-1)){
            return;
        }else{
            solve_milk4(curSet,curI+1,curQ);
        }
        curSet.erase(curSet.begin()+curSet.size()-1);
    }
}*/

int main_usaco_5_2_milk4(){
    fstream f_in("milk4.in",ios::in);
    fstream f_out("milk4.out",ios::out);

    f_in>>Q_milk4>>p_milk4;

    for(int i=0;i<p_milk4;i++){
        int tmp;
        f_in>>tmp;
        if(tmp<=Q_milk4){
            res_milk4.push_back(tmp);
            pail_milk4.push_back(tmp);
        }

    }
    sort(pail_milk4.begin(),pail_milk4.end());
    vector<int> curS;
    max_milk4=1;
    while(max_milk4<res_milk4.size()){
        if(solve_milk42(curS,0))
            break;
        max_milk4++;
    }

    // solve_milk4(curS,0,Q_milk4);
    f_out<<res_milk4.size();
    sort(res_milk4.begin(),res_milk4.end());
    for(int s : res_milk4)
        f_out<<" "<<s;
    f_out<<endl;
    f_out.close();
    return 0;
}