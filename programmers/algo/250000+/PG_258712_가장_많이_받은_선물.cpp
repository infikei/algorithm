// Solve 2025-10-08

#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = size(friends);
    unordered_map<string, int> friends_num;

    // 친구마다 번호 부여
    for (int i = 0; i < n; i++) {
        friends_num[friends[i]] = i;
    }

    vector<vector<int>> board(n, vector<int>(n, 0)); // 주고받은 선물의 수
    vector<int> score(n, 0); // 선물 지수

    for (string& gift : gifts) {
        stringstream ss(gift);
        string a, b;
        getline(ss, a, ' ');
        getline(ss, b, ' ');
        int a_idx = friends_num[a]; // 선물을 준 친구의 번호
        int b_idx = friends_num[b]; // 선물을 받은 친구의 번호
        board[a_idx][b_idx]++;
        score[a_idx]++;
        score[b_idx]--;
    }

    vector<int> n_gift(n, 0); // 각 친구마다 다음 달에 받을 선물의 수

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (board[i][j] > board[j][i]) {
                n_gift[i]++;
            }
            else if (board[i][j] < board[j][i]) {
                n_gift[j]++;
            }
            else if (score[i] > score[j]) {
                n_gift[i]++;
            }
            else if (score[i] < score[j]) {
                n_gift[j]++;
            }
        }
    }

    int ans = 0; // 가장 많은 선물을 받는 친구가 받을 선물의 수

    for (int& v : n_gift) {
        ans = max(ans, v);
    }

    return ans;
}
