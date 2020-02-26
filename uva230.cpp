//
// Created by 张楠 on 2019-12-11.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct book{
    string title;
    string author;
    int status;
    book(string title_1,string author_1){
        title=title_1;
        author=author_1;
        status=0;
    }
};

int compare(book b1,book b2){
    if(b1.author==b2.author)
        return b1.title<b2.title;
    return b1.author<b2.author;
}

int get_book_index(vector<book> &book_list,book b){
    int start=0;
    int end=book_list.size();
    int mid=0;
    while(start<=end){
        mid=(start+end)/2;
        book tmp_b=book_list[mid];
        if(tmp_b.title==b.title){
            break;
        }else{
            if(tmp_b.author==b.author){
                if(tmp_b.title<b.title)
                    start=mid+1;
                else
                    end=mid-1;
            }else{
                if(tmp_b.author<b.author)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
    }
    return (start+end)/2;
}

void borrow_book(vector<book> &book_list,book b){
    int index=get_book_index(book_list,b);
    //book_list.erase(book_list.begin()+index);
    book_list[index].status=-1;
}

void return_book(vector<book> &book_list,book b){
    int index=get_book_index(book_list,b);
    //book_list.erase(book_list.begin()+index);
    book_list[index].status=1;
}

int main_230(){
    vector<book> book_list;
    map<string,string> book_map;
    string line;
    getline(cin,line);
    while(line!="END"){
        string title;
        string author;
        int i = line.find("by",1);
        title = line.substr(0,i-1);
        author = line.substr(i+3,line.length()-i-3);

        book_list.push_back(book(title,author));
        book_map[title]=author;
        getline(cin,line);
    }
    sort(book_list.begin(),book_list.end(),compare);
    getline(cin,line);
    while(line!="END"){

        if(line[0]=='B'){
            string title=line.substr(7,line.length()-7);
            string author=book_map[title];
            book b=book(title,author);
            borrow_book(book_list,b);
        }else if(line[0]=='R'){
            string title=line.substr(7,line.length()-7);
            string author=book_map[title];
            book b=book(title,author);
            return_book(book_list,b);
        }else {
            for(int i=0;i<book_list.size();i++){
                if(book_list[i].status==1){
                    int j=i-1;
                    for(;j>=0;j--){
                        if(book_list[j].status==0){
                            break;
                        }
                    }
                    if(j>=0){
                        cout<<"Put "<<book_list[i].title<<" after "<<book_list[j].title<<endl;
                    }else{
                        cout<<"Put "<<book_list[i].title<<" first"<<endl;
                    }
                    book_list[i].status=0;
                }
            }
            cout<<"END"<<endl;

        }
        getline(cin,line);
    }
    return 0;
}
/*
"The Canterbury Tales" by Chaucer, G.
"The Canterbury Tale" by Chaucer, G.
"Algorithms" by Sedgewick, R.
"The C Programming Language" by Kernighan, B. and Ritchie, D.
END
BORROW "The Canterbury Tale"
BORROW "The C Programming Language"
BORROW "Algorithms"
RETURN "Algorithms"
RETURN "The C Programming Language"
RETURN "The Canterbury Tale"
SHELVE
BORROW "Algorithms"
BORROW "The C Programming Language"
BORROW "The Canterbury Tales"
RETURN "Algorithms"
RETURN "The C Programming Language"
RETURN "The Canterbury Tales"
SHELVE
END
*/