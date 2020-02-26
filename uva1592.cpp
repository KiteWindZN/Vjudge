//
// Created by 张楠 on 2019-12-02.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main_1592(){
    int n,m;
    while(cin>>n>>m){
        getchar();
        vector<vector<int>> strs(n,vector<int>());
        map<string,int> my_map;
        vector<string> str_set;
        for(int i=0;i<n;i++){
            string line;
            getline(cin,line);
            int start=0;
            for(int end=start+1;end<=line.length();end++){
                if(line[end]==','||end==line.length()){
                    string tmp_str=line.substr(start,end-start);
                    if(my_map.count(tmp_str)==0){
                        str_set.push_back(tmp_str);
                        my_map[tmp_str]=str_set.size();
                    }
                    strs[i].push_back(my_map[tmp_str]);
                    start=end+1;
                }
            }

        }
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> cols;
                for(int h=0;h<m;h++){
                    if(strs[i][h]==strs[j][h]){
                        cols.push_back(h);
                        if(cols.size()==2){
                            cout<<"NO"<<endl;
                            cout<<i+1<<" "<<j+1<<endl;
                            cout<<cols[0]+1<<" "<<cols[1]+1<<endl;
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
/*
4 4
How to compete in ACM ICPC,Peter,3,peter@neerc.ifmo.ru
How to win ACM ICPC,Michael,3,michael@neerc.ifmo.ra
Notes from ACM ICPC champion,Michael,4,michael@neerc.ifmo.ru
Notes from ACM ICPC champion,Michael,4,michael@neerc.ifmo.ru
2 3
1,Peter,peter@neerc.ifmo.ru
1,Peter,michael@neerc.ifmo.ru


3 3
How to compete in ACM ICPC,Peter,peter@neerc.ifmo.ru
How to win ACM ICPC,Michael,michael@neerc.ifmo.ru
Notes from ACM ICPC champion,Michael,michael@neerc.ifmo.ru
2 1
1
1
 */