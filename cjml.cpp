/*
//
// Created by 张楠 on 2020/9/8.
//

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int cnt_days(int m1, int d1, int m2, int d2,int ping[])
{
    int days=0;

    if(m1<m2){
        days=ping[m1-1]-d1;
        for(int i=m1+1;i<m2;i++){
            days+=ping[i-1];
        }
        days+=d2;

    }else if(m2==m1){
        if(d1<=d2){
            days=d2-d1;
        }else{
            days=ping[m1-1]-d1;
            for(int i=m1+1;i<=12;i++){
                days+=ping[i-1];
            }
            for(int i=1;i<m2;i++){
                days+=ping[i-1];
            }
            days+=d2;
        }
    }else {
        days=ping[m1-1]-d1;
        for(int i=m1+1;i<=12;i++){
            days+=ping[i-1];
        }
        for(int i=1;i<m2;i++){
            days+=ping[i-1];
        }
        days+=d2;
    }
    return days;
}




string guessYear(vector<vector<int>> &inputQueries) {
    // write your code here

    int ping[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};

    string res="";
    for(int i=0;i<inputQueries.size();i++) {
        int m1, d1, m2, d2, x;
        m1 = inputQueries[i][0];
        d1 = inputQueries[i][1];
        m2 = inputQueries[i][2];
        d2 = inputQueries[i][3];
        x = inputQueries[i][4];
        if(m1==2&&d1==29||(m2==2&&d2==29)){
            res+="R";
            continue;
        }

        int pingDays=cnt_days(m1,d1,m2,d2,ping);
        int leapDays=cnt_days(m1,d1,m2,d2,leap);
        if(pingDays==leapDays){
            res+="?";
        }else{
            if(pingDays==x){
                res+="P";
            }else{
                res+="R";
            }
        }

    }
    return res;

}

int main(){
    vector<vector<int>> nums;

    vector<int> tmp_1;
    vector<int> tmp_2;
    vector<int> tmp_3;
    vector<int> tmp_4;
    //[[2,28,3,2,2],[2,28,3,1,2],[12,31,1,1,1],[2,16,1,23,341]]
    tmp_1.push_back(12);
    tmp_1.push_back(2);
    tmp_1.push_back(12);
    tmp_1.push_back(28);
    tmp_1.push_back(26);

    tmp_1.push_back(12);
    tmp_1.push_back(29);
    tmp_1.push_back(1);
    tmp_1.push_back(28);
    tmp_1.push_back(30);


    tmp_2.push_back(2);
    tmp_2.push_back(28);
    tmp_2.push_back(3);
    tmp_2.push_back(1);
    tmp_2.push_back(2);

    //[[2,28,3,2,2],[2,28,3,1,2],[12,31,1,1,1],[2,16,1,23,341]]
    tmp_3.push_back(12);
    tmp_3.push_back(31);
    tmp_3.push_back(1);
    tmp_3.push_back(1);
    tmp_3.push_back(1);

    tmp_4.push_back(2);
    tmp_4.push_back(16);
    tmp_4.push_back(1);
    tmp_4.push_back(23);
    tmp_4.push_back(341);

    nums.push_back(tmp_1);
    nums.push_back(tmp_2);
    nums.push_back(tmp_3);
    nums.push_back(tmp_4);

    string str=guessYear(nums);
    cout<<str<<endl;
    return 0;
}

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}


*/
