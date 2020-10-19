//
// Created by 张楠 on 2020/10/18.
//

#include<iostream>
#include <math.h>
using namespace std;

long long solve_right_10366(int right,int maxIndexRight,int i,int maxRight,int height[]){
    long long ans=0;
    right=maxIndexRight+2;
    while(right<=i-2){
        maxRight=0;
        int tmpIndexRight=0;
        for(;right<=i-2;right=right+2){
            if(maxRight<height[right]){
                maxRight=height[right];
                tmpIndexRight=right;
            }
        }
        ans+=(tmpIndexRight-maxIndexRight)*height[tmpIndexRight];
        maxIndexRight=tmpIndexRight;
        right=tmpIndexRight+2;
    }
    return ans;
}

long long solve_left_10366(int left,int maxIndexLeft,int i, int maxLeft,int height[]){
    long long ans=0;
    left=maxIndexLeft-2;
    while(left>=0){
        maxLeft=0;
        int tmpIndexLeft=0;
        for(;left>=0;left-=2){
            if(height[left]>=maxLeft){
                maxLeft=height[left];
                tmpIndexLeft=left;
            }
        }
        ans+=(maxIndexLeft-tmpIndexLeft)*height[tmpIndexLeft];
        maxIndexLeft=tmpIndexLeft;
        left=tmpIndexLeft-2;
    }
    return ans;
}

int main(){
    int leftX,rightX;
    cin>>leftX>>rightX;
    while(leftX!=0&&rightX!=0){
        int height[3000];
        int i=0;
        int left=-leftX-1;
        int right=left+2;
        for(i=0;i<=(rightX-leftX);i+=2){
            cin>>height[i];
        }
        int maxLeft=0;
        int maxRight=0;
        int maxIndexLeft=left;
        int maxIndexRight=right;
        while(left>=0){
            if(height[left]>maxLeft){
                maxLeft=height[left];
                maxIndexLeft=left;
            }

            left-=2;
        }
        while(right<=i-2){
            if(height[right]>maxRight){
                maxRight=height[right];
                maxIndexRight=right;
            }
            right+=2;
        }

        long long ans=0;
        int lastmaxIndexLeft=maxIndexLeft;

        if(maxLeft>maxRight){ //右边出
            int t_index=maxIndexLeft;
            while(t_index<=(-leftX-1)){
                if(height[t_index]>=maxRight){
                    maxIndexLeft=t_index;
                }
                t_index+=2;
            }

            long long ans1=solve_right_10366(right,maxIndexRight,i,maxRight,height);

            ans=(maxIndexRight-maxIndexLeft)*maxRight;
            if(height[maxIndexLeft]>maxRight){
                ans+=ans1;
            }else{
                lastmaxIndexLeft=maxIndexLeft;
                t_index=maxIndexLeft;
                while(t_index>=0){
                    if(height[t_index]>maxRight){
                        maxIndexLeft=t_index;
                        break;
                    }
                    t_index-=2;
                }
                long long ans0=(lastmaxIndexLeft-maxIndexLeft)*maxRight;
                if(ans0>ans1){
                    ans+=(2*ans1);
                }else{
                    ans+=ans1+ans0;
                }
            }
            cout<<ans<<endl;
        }else if(maxLeft<maxRight){//左边出

            int t_index=maxIndexRight;
            while(t_index>=-leftX+1){
                if(height[t_index]>=maxLeft){
                    maxIndexRight=t_index;
                }
                t_index-=2;
            }
            ans=(maxIndexRight-maxIndexLeft)*maxLeft;
            long long  ans1=solve_left_10366(left,maxIndexLeft,i,maxLeft,height);
            if(height[maxIndexRight]>maxLeft){
                ans+=ans1;
            }else{
                t_index=maxIndexRight+2;
                lastmaxIndexLeft=maxIndexRight;
                while(t_index<=(i-2)){
                    if(height[t_index]>maxLeft){
                        maxIndexRight=t_index;
                        break;
                    }
                    t_index+=2;
                }
                long long ans0=(maxIndexRight-lastmaxIndexLeft)*maxLeft;
                if(ans0>ans1){
                    ans+=(2*ans1);
                }else{
                    ans+=ans0+ans1;
                }
            }

            cout<<ans<<endl;
        }else if(maxLeft==maxRight){
            ans=(maxIndexRight-maxIndexLeft)*maxRight;
            int ans1=solve_left_10366(left,maxIndexLeft,i,maxLeft,height);
            int ans2=solve_right_10366(right,maxIndexRight,i,maxRight,height);
            ans=ans+min(ans1,ans2)*2;
            cout<<ans<<endl;
        }

        cin>>leftX>>rightX;
    }
    return 0;
}