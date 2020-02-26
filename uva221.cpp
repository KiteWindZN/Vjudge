//
// Created by 张楠 on 2019-12-04.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Build{
    int id,x,y,width,depth,height;
};
int compare(Build b1,Build b2){
    if(b1.y==b2.y){
        return b1.x<b2.x;
    }
    return b1.y<b2.y;
}

int compare_1(Build b1,Build b2){
    if(b1.x==b2.x){
        return b1.y<b2.y;
    }
    return b1.x<b2.x;
}

int main_221(){
    int max_y=0;
    int max_x=0;
    int num;
    cin>>num;
    int start=1;
    while(num!=0){
        max_y=0;
        if(start>1){
            cout<<endl;
        }
        vector<Build> build_v(num);
        for(int i=0;i<num;i++){
            cin>> build_v[i].x>> build_v[i].y>> build_v[i].width>> build_v[i].depth>> build_v[i].height;
            build_v[i].id=i+1;
            if(max_y<build_v[i].y){
                max_y=build_v[i].y;
            }
            if(max_x<(build_v[i].x+build_v[i].width)){
                max_x=(build_v[i].x+build_v[i].width);
            }
        }
        sort(build_v.begin(),build_v.end(),compare);
        int height[max_x+1];
        memset(height,0, sizeof(height));
        vector<Build> res;
        for(int i=0;i<num;i++){
            int x,y,width,depth,heigh;
            x=build_v[i].x;
            y=build_v[i].y;
            width=build_v[i].width;
            depth=build_v[i].depth;
            heigh=build_v[i].height;
            int flag=0;
            for(int j=0;j<=width;j++){
                if(heigh>height[x+j]){
                    flag=1;
                    height[x+j]=heigh;
                }
            }
            if(flag==1){
                res.push_back(build_v[i]);
            }
        }
        sort(res.begin(),res.end(),compare_1);
        cout<<"For map #"<<start<<", the visible buildings are numbered as follows:"<<endl;
        cout<<res[0].id;
        for(int i=1;i<res.size();i++){
            cout<<" "<<res[i].id;
        }
        cout<<endl;
        cin>>num;
        start++;
    }

    return 0;
}