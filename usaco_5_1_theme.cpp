//
// Created by 张楠 on 2020/4/28.
//

/*
ID: 15605181
LANG: C++
TASK: theme
*/
#include <fstream>
using namespace std;
int theme[5000];
int true_theme[5000];
int T_theme;
int ans_theme=0;
int max_index_2=0;
void dfs_theme(int cur_len,int index_1,int index_2,int start_2){
    if(index_2>=T_theme|| index_1>=start_2){
        if(cur_len>ans_theme && cur_len>=5){
            ans_theme=cur_len-1;
        }
        if(index_2==T_theme){
            max_index_2=T_theme;
        }
        return;
    }

    if(true_theme[index_1]== true_theme[index_2] && index_1<start_2 && index_2<T_theme){
        dfs_theme(cur_len+1,index_1+1,index_2+1,start_2);
    }else{
        if(cur_len>ans_theme && cur_len>=5){
            ans_theme=cur_len-1;
        }
        return;
    }
}

void solve_theme(){
    int i=0;
    while(i<=T_theme-2*ans_theme){
        for(int j=i+4;j<T_theme-5;j++){
            if(true_theme[i]==true_theme[j]){
                max_index_2=0;
                dfs_theme(3,i+1,j+1,j-1);
                if(max_index_2==T_theme)
                    break;

            }
        }
        i++;
    }
}

int main_5_1_theme(){
    fstream f_in("theme.in",ios::in);
    fstream f_out("theme.out",ios::out);

    f_in>>T_theme;
    for(int i=0;i<T_theme;i++){
        int tmp;
        f_in>>tmp;
        theme[i]=tmp;
        if(i>0){
            true_theme[i]=theme[i]-theme[i-1];
        }
    }

    solve_theme();
    f_out<<ans_theme<<endl;
    f_out.close();
    return 0;
}