#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int MAX_N = 30, MAX_M = 7, MAX_WEIGHT = 500;
int n, weight[MAX_N], max_weight, m, marble[MAX_M];
bool dp[MAX_N + 1][MAX_N * MAX_WEIGHT + 1];

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        max_weight = max(max_weight, weight[i]);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> marble[i];
    }

    // dp 배열 : ilen개의 추를 사용해서 jsum 무게를 측정할 수 있는지 여부를 저장하는 배열
    dp[1][weight[0]] = true;
    for (int ilen = 2; ilen <= n; ilen++) {
        dp[ilen][weight[ilen - 1]] = true;
        for (int jsum = 1; jsum <= ilen * max_weight; jsum++) {
            if (dp[ilen - 1][jsum]) {
                dp[ilen][jsum] = true;
            }
            if (jsum > weight[ilen - 1] && dp[ilen - 1][jsum - weight[ilen - 1]]) {
                dp[ilen][jsum] = true;
            }
            if (weight[ilen - 1] > jsum && dp[ilen - 1][weight[ilen - 1] - jsum]) {
                dp[ilen][jsum] = true;
            }
            if (dp[ilen - 1][jsum + weight[ilen - 1]]) {
                dp[ilen][jsum] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (marble[i] > 15000) cout << "N ";
        else if (dp[n][marble[i]]) cout << "Y ";
        else cout << "N ";
    }
    cout << '\n';

    return 0;
}