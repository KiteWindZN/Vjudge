//
// Created by 张楠 on 2019-12-19.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

struct Text{
    int text_id;
    vector<string> content;
};

struct Bucket{
    int text_id;
    int row_id;
    bool operator < (const Bucket &a) const
    {
        if(a.text_id==text_id)
            return a.row_id > row_id;
        return a.text_id>text_id;
    }
};

void print_text(Text text){
    vector<string> content=text.content;
    for(int i=0;i<content.size();i++){
        cout<<content[i]<<endl;
    }
}

void search_query(vector<Text> text_list,map<string,vector<Bucket>> index_map,string A){

    if(index_map.count(A)==0){
        cout<<"Sorry, I found nothing."<<endl;
        return;
    }
    vector<Bucket> bucket_list=index_map[A];
    for(int i=0;i<bucket_list.size();i++){
        if(i>0 && bucket_list[i].text_id!=bucket_list[i-1].text_id){
            cout<<"---------"<<endl;
        }
        Bucket b=bucket_list[i];
        int text_id=b.text_id;
        int row_id=b.row_id;
        Text text=text_list[text_id];
        cout<<text.content[row_id]<<endl;
    }
}
void search_and_query(vector<Text> text_list,map<string,vector<Bucket>> index_map,string A,string B){
    set<Bucket> bucket_list;
    vector<Bucket> bucket_list_A=index_map[A];
    vector<Bucket> bucket_list_B=index_map[B];

    for(int i=0;i<bucket_list_A.size();i++){
        Bucket bucket_A=bucket_list_A[i];
        for(int j=0;j<bucket_list_B.size();j++){
            Bucket bucket_B=bucket_list_B[j];
            if(bucket_A.text_id==bucket_B.text_id){
                bucket_list.insert(bucket_A);
                if(bucket_A.row_id!=bucket_B.row_id){
                    bucket_list.insert(bucket_B);
                }
                for(int g=j+1;g<bucket_list_B.size();g++){
                    if(bucket_A.text_id==bucket_B.text_id && bucket_A.row_id!=bucket_B.row_id) {
                        bucket_list.insert(bucket_B);
                    }
                }
                break;
            }
        }
    }
    int i=0;
    int last=-1;
    set<Bucket>::iterator it=bucket_list.begin();
    for(;it!=bucket_list.end();it++){

        Bucket b=*it;
        int text_id=b.text_id;
        int row_id=b.row_id;
        if(i>0 && last!=text_id){
            cout<<"---------"<<endl;
        }
        Text text=text_list[text_id];
        cout<<text.content[row_id]<<endl;
        i++;
        last=text_id;
    }
}

void search_or_query(vector<Text> text_list,map<string,vector<Bucket>> index_map,string A,string B){
    set<Bucket> bucket_list;
    vector<Bucket> bucket_list_A=index_map[A];
    vector<Bucket> bucket_list_B=index_map[B];
    for(int i=0;i<bucket_list_A.size();i++){
        Bucket b=bucket_list_A[i];
        bucket_list.insert(b);
    }
    for(int i=0;i<bucket_list_B.size();i++){
        Bucket b=bucket_list_B[i];
        bucket_list.insert(b);
    }

    set<Bucket>::iterator it=bucket_list.begin();
    int i=0;
    int last=-1;
    for(;it!=bucket_list.end();it++){
        Bucket b=*it;
        int text_id=b.text_id;
        int row_id=b.row_id;
        if(i>0 && last!=text_id){
            cout<<"---------"<<endl;
        }
        Text text=text_list[text_id];
        cout<<text.content[row_id]<<endl;
        i++;
        last=text_id;
    }
}

void search_not_query(vector<Text> text_list,map<string,vector<Bucket>> index_map,string A,int N){
    set<int> text_index_set;
    for(int i=0;i<N;i++){
        text_index_set.insert(i);
    }
    vector<Bucket> bucket_list=index_map[A];
    for(int i=0;i<bucket_list.size();i++){
        int text_id=bucket_list[i].text_id;
        text_index_set.erase(text_id);
    }
    if(text_index_set.empty()){
        cout<<"Sorry, I found nothing."<<endl;
        return;
    }
    set<int>::iterator it=text_index_set.begin();
    print_text(text_list[*it]);
    it++;
    for(;it!=text_index_set.end();it++){
        cout<<"---------"<<endl;
        print_text(text_list[*it]);
    }
}

bool is_buckets_equal(Bucket b1,Bucket b2){
    if(b1.text_id==b2.text_id && b1.row_id==b2.row_id)
        return true;
    return false;
}


int main_1597(){
    int N,M;
    cin>>N;
    getchar();
    vector<Text> text_list;
    map<string,vector<Bucket>> index_map;
    set<string> stop_words;
    //“the, a, to, and, or, not
    stop_words.insert("the");
    stop_words.insert("a");
    stop_words.insert("to");
    stop_words.insert("and");
    stop_words.insert("or");
    stop_words.insert("not");
    for(int i=0;i<N;i++){
        string line;
        Text text;
        text.text_id=i;

        for(int r=0;;r++){
            getline(cin,line);
            if(line=="**********") {
                text_list.push_back(text);
                break;
            }
            int len=line.length();
            text.content.push_back(line);
            for(int j=0;j<len;j++){
                if(isalpha(line[j]))
                    line[j]=tolower(line[j]);
                else
                    line[j]=' ';
            }
            stringstream ss(line);
            string tmp;
            while(ss>>tmp) {
                if (stop_words.count(tmp))
                    continue;
                Bucket bucket;
                bucket.text_id = i;
                bucket.row_id = r;

                if (index_map.count(tmp) == 0 || !is_buckets_equal(index_map[tmp][index_map[tmp].size() - 1], bucket)) {
                    index_map[tmp].push_back(bucket);
                }
            }
        }

    }
    cin>>M;
    getchar();
    for(int i=0;i<M;i++){
        string line;
        getline(cin,line);
        stringstream ss(line);
        vector<string> tmp_list;
        string tmp_str;
        while(ss>>tmp_str)
            tmp_list.push_back(tmp_str);

        if(tmp_list.size()==1){
            string A=tmp_list[0];
            search_query(text_list,index_map,A);
        }else if(tmp_list.size()==2){
            string A=tmp_list[1];
            search_not_query(text_list,index_map,A,N);
        }else if(tmp_list.size()==3){
            string A=tmp_list[0];
            string B=tmp_list[2];
            if(tmp_list[1]=="AND"){
                search_and_query(text_list,index_map,A,B);
            }else{
                search_or_query(text_list,index_map,A,B);
            }
        }
        cout<<"=========="<<endl;
    }
}