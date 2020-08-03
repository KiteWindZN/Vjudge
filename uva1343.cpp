//
// Created by 张楠 on 2020/5/1.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int LEN_1343 = 8, maxN_1343 = 24;
int graph_1343[maxN_1343];
int board_1343[LEN_1343][LEN_1343 - 1] = {
        {0,  2,  6,  11, 15, 20, 22},
        {1,  3,  8,  12,  17, 21, 23},
        {10, 9,  8,  7,  6,  5,  4},
        {19, 18, 17, 16, 15, 14, 13},
        {23, 21, 17, 12, 8,  3,  1},
        {22, 20, 15, 11, 6,  2,  0},
        {13, 14, 15, 16, 17, 18, 19},
        {4,  5,  6,  7,  8,  9,  10}};
int check_1343[] = {6, 7, 8, 11, 12, 15, 16, 17};
int res_1343[30];
int maxd_1343;

void rotate_1343(int index) {
    int t = graph_1343[board_1343[index][0]];
    for (int i = 1; i < LEN_1343 - 1; i++) {
        int index1 = board_1343[index][i - 1];
        int index2 = board_1343[index][i];
        graph_1343[index1] = graph_1343[index2];
    }
    int index1 = board_1343[index][LEN_1343 - 2];
    graph_1343[index1] = t;
}

int check_broad() {
    int n1 = 0, n2 = 0, n3 = 0;
    for (int i = 0; i < LEN_1343; i++) {
        if (graph_1343[check_1343[i]] == 1)
            n1++;
        else if (graph_1343[check_1343[i]] == 2)
            n2++;
        else if (graph_1343[check_1343[i]] == 3)
            n3++;
    }
    return LEN_1343 - max(max(n1, n2), n3);
}

bool solve_1343(int d) {
    int need = check_broad();
    if (need == 0) {
        return true;
    }
    if (maxd_1343 - d < need)
        return false;
    int tmpG[maxN_1343];
    memcpy(tmpG, graph_1343, sizeof(graph_1343));
    for (int i = 0; i < LEN_1343; i++) {
        rotate_1343(i);
        res_1343[d] = i + 'A';
        if (solve_1343(d + 1))
            return true;
        memcpy(graph_1343, tmpG, sizeof(graph_1343));
    }
    return false;
}

int main_uva1343() {
    while (cin >> graph_1343[0]) {
        if (graph_1343[0] == 0)
            break;
        for (int i = 1; i < 24; i++) {
            cin >> graph_1343[i];
        }

        if (check_broad() == 0) {
            cout << "No moves needed" << endl;
            cout << graph_1343[check_1343[0]] << endl;
            continue;
        }
        for (maxd_1343 = 1; maxd_1343 < 30; maxd_1343++)
            if (solve_1343(0))
                break;

        for (int j = 0; j < maxd_1343; j++)
            //cout<<res_1343[j];
            printf("%c", res_1343[j]);
        cout << endl;
        cout << graph_1343[check_1343[0]] << endl;
    }
    return 0;
}