//
// Created by 张楠 on 2020/10/22.
//

#include <iostream>
#include <cstring>
using namespace std;

int s_11584[1010][1010];
int dp_11584[1010];
int main_uva11584(){
    int n;
    cin>>n;
    while(n--){
        string line;
        cin>>line;
        int len=line.length();

        memset(s_11584,0,sizeof(s_11584));

        for(int i=0;i<len;i++){
            dp_11584[i]=i+1;
            s_11584[i][i]=1;
            int left=i-1;
            int right=i+1;
            while(left>=0&&right<len){
                if(line[left]==line[right]){
                    s_11584[left][right]=1;
                }
                else{
                    break;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0&&right<len){
                if(line[left]==line[right]){
                    s_11584[left][right]=1;
                }else{
                    break;
                }

                left--;
                right++;
            }
        }
        dp_11584[0]=1;
        for(int i=1;i<len;i++){
            for(int j=0;j<=i;j++){
                if(s_11584[j][i]){
                    if(j==0){
                        dp_11584[i]=1;
                    }else{
                        dp_11584[i]=min(dp_11584[i],dp_11584[j-1]+1);
                    }
                }
            }
        }
        cout<<dp_11584[len-1]<<endl;
    }
    return 0;
}