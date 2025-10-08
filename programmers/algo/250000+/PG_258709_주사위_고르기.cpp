// Solve 2025-10-08

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

void init_vec(vector<int>& v) {
    for (int i = 0; i < size(v); i++) {
        v[i] = 0;
    }
}

void get_count_of_sum(vector<vector<int>>& dice, vector<int>& chosen, vector<int>& ret) {
    vector<int> tmp(501);
    init_vec(ret);
    ret[0] = 1;

    for (int idx : chosen) {
        init_vec(tmp);

        for (int j = 0; j < 6; j++) {
            int num = dice[idx][j];

            for (int u = num; u <= 500; u++) {
                tmp[u] += ret[u - num];
            }
        }

        swap(ret, tmp);
    }
}

pii get_result(vector<vector<int>>& dice, vector<int>& mine, vector<int>& others) {
    vector<int> my_cnt(501);
    vector<int> others_cnt(501);
    get_count_of_sum(dice, mine, my_cnt);
    get_count_of_sum(dice, others, others_cnt);

    int win = 0; // 이길 경우의 수
    int draw = 0; // 비길 경우의 수
    int prefix_sum = 0;

    for (int i = 1; i <= 500; i++) {
        // i가 나한테 나올 가짓수 * i보다 작은 수가 상대방에게 나올 가짓수
        win += my_cnt[i] * prefix_sum;
        // i가 나한테 나올 가짓수 * i가 상대방에게 나올 가짓수
        draw += my_cnt[i] * others_cnt[i];

        prefix_sum += others_cnt[i];
    }

    int all_cnt = pow(6, (int) size(dice)); // 전체 경우의 수
    int lose = all_cnt - win - draw; // 질 경우의 수
    return {win, lose};
}

vector<int> solution(vector<vector<int>> dice) {
    int n = size(dice);
    vector<int> ans;
    int max_win = 0;

    // bit 연산으로 n/2개 선택
    // 단, 0번 비트는 항상 켜져있도록 함 (mine에 0이 항상 포함되도록)
    for (int b = 1; b < (1 << n); b += 2) {
        // 정확히 n/2개 고르는 경우만 탐색
        if (__builtin_popcount(b) != n / 2) continue;

        vector<int> mine, others;

        // 0번부터 n-1번까지의 주사위를 mine과 others로 분할
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) {
                mine.push_back(i);
            }
            else {
                others.push_back(i);
            }
        }

        // mine의 입장에서 이긴 횟수와 진 횟수 구하기
        pii res = get_result(dice, mine, others);
        int win = res.first;
        int lose = res.second;

        // mine의 이긴 횟수가 현재까지의 가장 큰 이긴 횟수라면 갱신
        if (win > max_win) {
            max_win = win;
            ans = mine;
        }

        // others의 이긴 횟수가 현재까지의 가장 큰 이긴 횟수라면 갱신
        if (lose > max_win) {
            max_win = lose;
            ans = others;
        }
    }

    // 0-index에서 1-index로 변환
    for (int& d : ans) d++;

    return ans;
}
