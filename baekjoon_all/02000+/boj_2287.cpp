// Solve 2025-11-21

// 유사 문제 : 프로그래머스 N으로 표현

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int k;
set<int> memo[9];

void init() {
    int tmp = 0;

    for (int i = 1; i <= 8; i++) {
        tmp = tmp * 10 + k;
        memo[0].insert(tmp);
        memo[i].insert(tmp);
    }

    for (int i = 2; i <= 8; i++) {
        for (int j = i / 2; j >= 1; j--) {
            int jj = i - j;

            for (int u : memo[j]) {
                for (int v : memo[jj]) {
                    if (u == 0 || v == 0) continue;

                    tmp = u + v;

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }

                    tmp = u >= v ? u - v : v - u;

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }

                    tmp = u * v;

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }

                    tmp = u >= v ? u / v : v / u;

                    if (memo[0].find(tmp) == memo[0].end()) {
                        memo[0].insert(tmp);
                        memo[i].insert(tmp);
                    }
                }
            }
        }
    }
}

void solution() {
    int a;
    cin >> a;

    for (int i = 1; i <= 8; i++) {
        if (memo[i].find(a) != memo[i].end()) {
            cout << i << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    FASTIO;

    int n;
    cin >> k >> n;

    init();

    while (n-- > 0) {
        solution();
    }

    return 0;
}
