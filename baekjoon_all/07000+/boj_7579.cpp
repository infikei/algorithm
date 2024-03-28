// Solve 2023-01-05
// Update 2024-03-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int memory[100];

    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }

    int cost[100];

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    // memo[c] : c의 비용으로 확보할 수 있는 최대한의 메모리
    int memo[10001] = { 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 10000; j >= cost[i]; j--) {
            memo[j] = max(memo[j], memo[j - cost[i]] + memory[i]);
        }
    }

    int idx = lower_bound(memo, memo + 10001, m) - memo;
    cout << idx << '\n';

    return 0;
}
