//
// Created by 张楠 on 2020/10/25.
//

#include <iostream>
using namespace std;

unsigned long long Fibonacii_11582[1000000+2];
int M_11582;
void solve_11582(int index,int n){
    Fibonacii_11582[0]=0;
    Fibonacii_11582[1]=1;
    for(int i=2;i<=index;i++){
        Fibonacii_11582[i]=(Fibonacii_11582[i-1]+Fibonacii_11582[i-2])%n;
        if(Fibonacii_11582[i]==1 && Fibonacii_11582[i-1]==0){
            M_11582=i-1;
            return ;
        }
    }
}

int main_uva11582(){
    int T;
    cin>>T;
    unsigned long long a,b;
    int n;

    while(T--){
        cin>>a>>b>>n;

        if(a==0 || n==1){
            cout<<0<<endl;
            continue;
        }

        solve_11582(n*n,n);
        a=a%M_11582;
        //b=b%M_11582;
        int num=1;
        while(b){
            if(b&1) {
                num=(num*a)%M_11582;
            }
            a=(a*a)%M_11582;
            b>>=1;
        }
        cout<<Fibonacii_11582[num]<<endl;
    }
    return 0;
}