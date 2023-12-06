// Solve 2023-12-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    int n;
    cin >> s >> n;

    int s_cnt[10] = { 0 };

    for (char c : s) {
        s_cnt[c - '0']++;
    }

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;

        int x_cnt[10] = { 0 };

        for (char c : x) {
            x_cnt[c - '0']++;
        }

        int a = 0;

        for (int d = 0; d < 10; d++) {
            a += min(s_cnt[d], x_cnt[d]);
        }

        int b = 0;

        for (int j = 0; j < 4; j++) {
            if (s[j] == x[j]) {
                b++;
            }
        }

        cout << a << ' ' << b << '\n';
    }

    return 0;
}
