//
// Created by 张楠 on 2019-12-10.
//


#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct point{
    int x,y;
    point(int x_1,int y_1){
        x=x_1;
        y=y_1;
    }
    bool operator<(const point& tmp) const{

        if(this->x<tmp.x)
            return true;
        else{
            if(this->x==tmp.x){
                if(this->y<tmp.y)
                    return true;
                else
                    return false;
            }else
                return false;
        }

    }
};

int main_1595(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int max_x=-10000;
        int min_x=10000;
        int n;
        cin>>n;
        set<point> point_set;
        vector<point> point_list;
        for(int j=0;j<n;j++){
            int x,y;
            cin>>x>>y;
            if(x<min_x)
                min_x=x;
            if(x>max_x)
                max_x=x;
            point_set.insert(point(x,y));
            point_list.push_back(point(x,y));
        }
        double line_x=(min_x+max_x)/2.0;
        int flag=0;
        for(int j=0;j<point_list.size();j++){
            point p=point_list[j];
            int x=p.x;
            int y=p.y;
            int x_1=line_x*2-x;
            point p_1=point(x_1,y);
            if(point_set.count(p_1)==0){
                flag=1;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}