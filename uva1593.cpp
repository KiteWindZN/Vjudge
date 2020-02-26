//
// Created by 张楠 on 2019-12-05.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main_1593(){
    vector<vector<string>> strs;
    string line;
    vector<int> strs_len;
    fill(strs_len.begin(),strs_len.end(),0);
    int g=0;
    while(getline(cin,line)){
        //getline(cin,line);
        line=line+' ';
        vector<string> list_str;
        int start=0;
        while(line[start]==' ')
            start++;
        int end=start+1;
        for(;end<line.length();end++){
            if(line[end]==' '){
                string tmp=line.substr(start,end-start);
                list_str.push_back(tmp);
                if(strs_len.size()>=list_str.size()){
                    if(strs_len[list_str.size()-1]<tmp.length())
                        strs_len[list_str.size()-1]=tmp.length();
                }else{
                    strs_len.push_back(tmp.length());
                }
                start=end+1;
                while(line[start]==' ')
                    start++;
                end=start;
            }

        }

        strs.push_back(list_str);
    }

    for(int i=0;i<strs.size();i++){
        for(int j=0;j<strs[i].size();j++){
            cout<<strs[i][j];
            if(j<strs[i].size()-1){
                int dis=strs_len[j]-strs[i][j].length()+1;
                for(int h=0;h<dis;h++){
                    cout<<' ';
                }
            }
        }
        cout<<endl;
    }


    return 0;
}
/*
  start:  integer;    // begins here
stop: integer; //  ends here
 s:  string;
c:   char; // temp
 */