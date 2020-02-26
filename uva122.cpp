//
// Created by 张楠 on 2019-12-31.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;

    Node(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
};

void print_tree(Node *root){
    queue<Node *> q;
    cout<<root->value;

    if(root->left!=NULL){
        q.push(root->left);
    }
    if(root->right!=NULL){
        q.push(root->right);
    }


    while(q.size()>0){
        Node *tmp=q.front();
        q.pop();
        cout<<" "<<tmp->value;
        if(tmp->left!=NULL){
            q.push(tmp->left);
        }
        if(tmp->right!=NULL){
            q.push(tmp->right);
        }
    }
    cout<<endl;
}

int addNode(Node *root,string n_sort,int value){
    Node *tmp=root;
    if(n_sort.length()==0){
        if(root->value!=0){
            return -257;
        }
        root->value=value;
        return -1;
    }
    int count=0;
    for(int i=0;i<n_sort.length();i++){
        if(n_sort[i]=='L'){
            if(tmp->left==NULL){
                Node *t=(Node*)malloc(sizeof(Node));
                t->value=0;
                t->left=NULL;
                t->right=NULL;
                tmp->left=t;
                count++;
            }
            tmp=tmp->left;
        }else{
            if(tmp->right==NULL){
                Node *t=(Node*)malloc(sizeof(Node));
                t->value=0;
                t->left=NULL;
                t->right=NULL;
                tmp->right=t;
                count++;
            }
            tmp=tmp->right;
        }
    }
    if(tmp->value==0){
        count--;
    }else{
        return -257;
    }
    tmp->value=value;
    return count;
}

int main_uva122(){
    string line;
    while(cin>>line){
        Node *root=(Node*)malloc(sizeof(Node));
        root->value=0;
        root->left=NULL;
        root->right=NULL;
        int count=1;
        int flag=0;
        while(line!="()"){
            if(flag==0){
                int p=line.find(",");
                int value=atoi(line.substr(1,p).c_str());
                string n_sort=line.substr(p+1,line.length()-p-2);
                int tmp_res=addNode(root,n_sort,value);
                if(tmp_res==-257){
                    flag=1;
                }
                count+=tmp_res;
            }

            cin>>line;
        }
        if(count!=0|| flag==1){
            cout<<"not complete"<<endl;
        }else
            print_tree(root);
    }

    return 0;
}