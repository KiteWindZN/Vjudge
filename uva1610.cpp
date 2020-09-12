//
// Created by 张楠 on 2020/9/12.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve_1610(string str1,string str2){
    int len=min(str1.length(),str2.length());
    int ans=0;
    for(int i=0;i<len;i++){
        if(str1[i]!=str2[i])
            return ans;
        ans++;
    }
    return ans;
}

int main_1610(){
    int T;
    cin>>T;
    while(T>0){
        vector<string> names;
        for(int i=0;i<T;i++){
            string str;
            cin>>str;
            names.push_back(str);
        }
        sort(names.begin(),names.end());

        /* for(int i=0;i<names.size();i++){
             cout<<names[i]<<endl;
         }*/
        int index2=T/2;
        int index1=index2-1;

        string str1=names[index1];
        string str2=names[index2];
        int ans=solve_1610(str1,str2);

        string resStr=str1.substr(0,ans);
        if(ans==str1.length() || ans==str1.length()-1){
            resStr=str1;
        }else{
            if(str2[ans]-str1[ans]>1 || ans != str2.size() - 1){
                char ch=str1[ans]+1;
                resStr+=ch;
            }else if(str2[ans]-str1[ans]==1){
                resStr+=str1[ans];
                for(int i=ans+1;i<str1.length();i++){
                    if(str1.length()-1==i){
                        resStr+=str1[i];
                        break;
                    }
                    if(str1[i]!='Z'){
                        resStr+=str1[i]+1;
                        break;
                    }else{
                        resStr+=str1[i];
                    }
                }
            }
        }
        cout<<resStr<<endl;
        cin>>T;
    }
    return 0;
}

/*
2
ABZAZZ
ABZBAA
abzazz
abzb*/
