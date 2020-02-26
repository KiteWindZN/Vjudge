//
// Created by 张楠 on 2019-12-28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

deque<int> ready_queue;
queue<int> block_queue;
int time_map[5];
int pgm_num;
int time_qum;
vector<string> pgm_que[1005];
int q[1005];
int value_list[26];
int lock_num=-1;

void run(int choose_num){
    int cur_time=time_qum;

    while(cur_time>0){
        string command=pgm_que[choose_num][q[choose_num]];

        if(command[2]=='='){
            cur_time-=time_map[0];

            int v = command[4] - '0';
            if(command.size() == 6) v = v * 10 + command[5] - '0';
            value_list[command[0]-'a']=v;

        }else if(command[2]=='i'){
            cur_time-=time_map[1];
            cout<<choose_num<<": "<<value_list[command[6]-'a']<<endl;

        }else if(command[2]=='c'){
            cur_time-=time_map[2];

            if(lock_num==-1){
                lock_num=choose_num;
            }else{
                block_queue.push(choose_num);
                return;
            }

        }else if(command[2]=='l'){
            cur_time-=time_map[3];

            if(!block_queue.empty()){
                int b_num=block_queue.front();
                block_queue.pop();
                ready_queue.push_front(b_num);
            }
            lock_num=-1;
        }else if(command[2]=='d'){
            return ;
        }
        q[choose_num]++;
    }
    ready_queue.push_back(choose_num);
}

int main_uva210(){
    int T;
    cin>>T;
    while(T--){

        memset(q,0, sizeof(q));
        memset(value_list,0, sizeof(value_list));

        scanf("%d", &pgm_num);
        for(int i = 0; i < 5; ++i)
            scanf("%d", &time_map[i]);
        scanf("%d", &time_qum);

        getchar();
        for(int i=1;i<=pgm_num;i++){
            ready_queue.push_back(i);
            pgm_que[i].clear(); //important!!!!
            string line;
            getline(cin,line);
            while(line!="end"){
                if(line == "") continue;
                pgm_que[i].push_back(line);
                getline(cin,line);
            }
            pgm_que[i].push_back(line);
        }

        while(!ready_queue.empty()){
            int choose_num=ready_queue.front();
            ready_queue.pop_front();
            run(choose_num);
        }
        if(T)
            puts("");
    }

    return 0;
}

/*
3 2 1 1 1 1 2
a = 4
print a
lock
b = 9
print b
unlock
print b
end
a = 3
print a
lock
b = 8
print b
unlock
print b
end
b = 5
a = 17
print a
print b
lock
b = 21
print b
unlock
print b
end
*/
