//
// Created by 张楠 on 2019-12-29.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void command_1(int left[],int right[],int X,int Y){
    if(left[Y]==X)
        return;
    int l_x=left[X];
    int r_x=right[X];

    right[l_x]=r_x;
    left[r_x]=l_x;

    left[X]=left[Y];
    right[left[Y]]=X;
    right[X]=Y;
    left[Y]=X;
}

void command_2(int left[],int right[],int X,int Y){
    if(right[Y]==X)
        return ;
    int l_x=left[X];
    int r_x=right[X];

    right[l_x]=r_x;
    left[r_x]=l_x;

    right[X]=right[Y];
    left[right[Y]]=X;

    right[Y]=X;
    left[X]=Y;
}

void command_3(int left[],int right[],int X,int Y){

    if(right[X]==Y){
        int l_x=left[X];
        int r_y=right[Y];
        left[Y]=l_x;
        right[l_x]=Y;

        right[X]=r_y;
        left[r_y]=X;

        left[X]=Y;
        right[Y]=X;

    }else if(left[X]==Y){
        int r_x=right[X];
        int l_y=left[Y];

        right[Y]=r_x;
        left[r_x]=Y;

        left[X]=l_y;
        right[l_y]=X;

        right[X]=Y;
        left[Y]=X;
    }else{
        int l_x=left[X];
        int r_x=right[X];

        int l_y=left[Y];
        int r_y=right[Y];

        right[l_x]=Y;
        right[Y]=r_x;
        left[r_x]=Y;
        left[Y]=l_x;

        right[l_y]=X;
        right[X]=r_y;
        left[r_y]=X;
        left[X]=l_y;
    }


}

void print_link(int left[],int right[],int flag,int n){
    int count=0;
    long long sum=0;
    if(flag==0){
        for(int i=right[0];i!=n+1;i=right[i]){
            if(count%2==0){
                sum+=i;
            }
            count++;
        }
    }else{
        for(int i=left[n+1]; i!=0;i=left[i]){
            if(count%2==0){
                sum+=i;
            }
            count++;
        }
    }
    cout<<sum<<endl;
}
int main_uva12675(){
    int n,m;
    int count=1;
    while(cin>>n>>m){
        int left[n+2];
        int right[n+2];
        for(int i=1;i<n+1;i++){
            left[i]=i-1;
            right[i]=i+1;
        }
        right[0]=1;
        left[0]=0;
        left[n+1]=n;
        right[n+1]=n+1;
        int flag=0;
        for(int i=0;i<m;i++){
            int index;
            cin>>index;
            if(index==1){
                int X,Y;
                cin>>X>>Y;
                if(flag==0){
                    command_1(left,right,X,Y);
                }else{
                    command_2(left,right,X,Y);
                }

            }else if(index==2){
                int X,Y;
                cin>>X>>Y;
                if(flag==0){
                    command_2(left,right,X,Y);
                }else{
                    command_1(left,right,X,Y);
                }

            }else if(index==3){
                int X,Y;
                cin>>X>>Y;
                command_3(left,right,X,Y);

            }else{

                flag=flag^1;
            }
        }
        cout<<"Case "<<count<<": ";
        count++;
        print_link(left,right,flag,n);
    }
    return 0;
}
/*
6 4
1 1 4
2 3 5
3 1 2
4
6 3
1 1 4
2 3 5
3 1 6
100000 1
4
 */