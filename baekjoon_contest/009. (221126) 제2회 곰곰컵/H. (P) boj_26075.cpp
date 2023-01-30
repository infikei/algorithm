#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ull = unsigned long long;

int main() {
    fastio;

    int N, M;
    cin >> N >> M;
    int NM = N + M;

    string S[2];
    vector<int> idx_of_1[2];

    for (int i = 0; i < 2; i++) {
        cin >> S[i];

        for (int j = 0; j < NM; j++) {
            if (S[i][j] == '1') {
                idx_of_1[i].push_back(j);
            }
        }
    }

    ull cnt = 0;
    for (int j = 0; j < M; j++) {
        cnt += (ull)abs(idx_of_1[0][j] - idx_of_1[1][j]);
    }

    ull ans = 0, k = cnt / 2;
    if (cnt % 2 == 0) {
        ans = k * k * 2;
    }
    else {
        ans = (k + 1) * k * 2 + 1;
    }
    cout << ans << '\n';

    return 0;
}