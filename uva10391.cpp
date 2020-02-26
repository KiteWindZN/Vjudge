//
// Created by 张楠 on 2019-12-06.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main_10391(){
    vector<string> words;
    set<string> word_set;
    string line;
    while(cin>>line){
        words.push_back(line);
        word_set.insert(line);
    }

    for(int i=0;i<words.size();i++){
        int len=words[i].length();

        for(int j=1;j<=len-1;j++){
            string str1=words[i].substr(0,j);
            string str2=words[i].substr(j);
            if(word_set.count(str1)!=0 && word_set.count(str2) != 0){
                cout<<words[i]<<endl;
                break;
            }
        }
    }
    return 0;
}

/*
a
aa
aalien
aborn
alien
born
borna
less
lien
never
nevertheless
new
newa
newborn
the
zebra
*/