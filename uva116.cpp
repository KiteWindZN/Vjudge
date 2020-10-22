//
// Created by 张楠 on 2020/10/20.
//
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int nums_116[12][110];
long long dp_116[12][110];
int n_116,m_116;
const long long max_116=10e9;
int main_uva116(){
    while(cin>>n_116>>m_116){

        for(int i=0;i<n_116;i++){
            for(int j=0;j<m_116;j++){
                cin>>nums_116[i][j];
            }
        }
        for(int i=0;i<n_116;i++)
            dp_116[i][m_116-1]=nums_116[i][m_116-1];
        int start=m_116-2;
        while(start>=0){
            for(int i=0;i<n_116;i++){
                int col=start+1;
                int row1=i;
                int row2=(i-1+n_116)%n_116;
                int row3=(i+1)%n_116;
                dp_116[i][start]=min(dp_116[row1][col],min(dp_116[row2][col],dp_116[row3][col]))+nums_116[i][start];
            }
            start--;
        }
        int ans=dp_116[0][0];
        int startRow=0;
        for(int i=0;i<n_116;i++){
            if(ans>dp_116[i][0]){
                ans=dp_116[i][0];
                startRow=i;
            }
        }

        int tmp=nums_116[startRow][0];
        cout<<(startRow+1);
        for(int i=1;i<m_116;i++){
            int row1=(startRow+1)%n_116;
            int row2=startRow;
            int row3=(startRow-1+n_116)%n_116;
            vector<int> tmpList;
            tmpList.push_back(row1);
            tmpList.push_back(row2);
            tmpList.push_back(row3);
            sort(tmpList.begin(),tmpList.end());
            for(int j=0;j<3;j++){
                if(tmp+dp_116[tmpList[j]][i]==ans){
                    tmp+=nums_116[tmpList[j]][i];
                    cout<<" "<<tmpList[j]+1;
                    startRow=tmpList[j];
                    break;
                }
            }
        }
        cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

