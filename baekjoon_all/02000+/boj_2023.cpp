// Solve 2024-01-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n;

bool is_prime(int k) {
    if (k == 1) return false;

    for (int i = 2, ie = sqrt(k); i <= ie; i++) {
        if (k % i == 0) {
            return false;
        }
    }

    return true;
}

void dfs(int depth = 0, int num = 0) {
    if (depth == n) {
        cout << num << '\n';
        return;
    }

    int next_num = num * 10;

    for (int i = 1; i <= 9; i++) {
        if (is_prime(++next_num)) {
            dfs(depth + 1, next_num);
        }
    }
}

int main() {
    FASTIO;

    cin >> n;

    dfs();

    return 0;
}
