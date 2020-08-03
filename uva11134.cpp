//
// Created by 张楠 on 2020/8/3.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int max_11134=5005;
int resX_11134[max_11134];
int resY_11134[max_11134];

struct Node_11134{
    int start;
    int end;
    int index;

    bool operator < (const Node_11134 &a) const
    {
        if(a.end==end)
            return a.start > start;
        return a.end>end;
    }
    Node_11134(){
        this->start=0;
        this->end=0;
        this->index=0;
    }
};

Node_11134 nodeListX_11134[max_11134];
Node_11134 nodeListY_11134[max_11134];

int main_11134(){
    int n;
    cin>>n;
    while(n!=0){
        int flagX[n+1];
        int flagY[n+1];
        for(int i=0;i<n;i++){
            cin>>nodeListX_11134[i].start>>nodeListY_11134[i].start>>nodeListX_11134[i].end>>nodeListY_11134[i].end;
            nodeListX_11134[i].index=i;
            nodeListY_11134[i].index=i;
            flagX[i+1]=0;
            flagY[i+1]=0;
        }

        sort(nodeListX_11134,nodeListX_11134+n);
        sort(nodeListY_11134,nodeListY_11134+n);


        int impossiable=1;
        for(int i=0;i<n;i++){
            impossiable=1;
            int startx=nodeListX_11134[i].start;
            int endx=nodeListX_11134[i].end;
            for(int j=startx;j<=endx;j++){
                if(flagX[j]==0){
                    impossiable=0;
                    resX_11134[nodeListX_11134[i].index]=j;
                    flagX[j]=1;
                    break;
                }
            }
            if(impossiable==1){
                break;
            }
        }
        if(impossiable==1){
            cout<<"IMPOSSIBLE"<<endl;
            cin>>n;
            continue;
        }
        impossiable=1;

        for(int i=0;i<n;i++){
            impossiable=1;
            int starty=nodeListY_11134[i].start;
            int endy=nodeListY_11134[i].end;
            for(int j=starty;j<=endy;j++){
                if(flagY[j]==0){
                    impossiable=0;
                    resY_11134[nodeListY_11134[i].index]=j;
                    flagY[j]=1;
                    break;
                }
            }
            if(impossiable==1){
                break;
            }
        }
        if(impossiable==1){
            cout<<"IMPOSSIBLE"<<endl;
            cin>>n;
            continue;
        }
        for(int i=0;i<n;i++){
            cout<<resX_11134[i]<<" "<<resY_11134[i]<<endl;
        }
        cin>>n;

    }
    return 0;
}

/*
8
1 1 2 2
5 7 8 8
2 2 5 5
2 2 5 5
6 3 8 6
6 3 8 5
6 3 8 8
3 6 7 8
8
1 1 2 2
1 1 2 2
2 2 5 5
2 2 5 5
6 3 8 6
6 3 8 5
6 3 8 8
1 1 2 2
4
1 1 4 4
1 1 4 4
1 1 4 4
2 2 3 3
0*/
