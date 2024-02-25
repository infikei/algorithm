// Solve 2024-02-24

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
    cin >> s;

    string ksa = "KSA";

    int max_count = 0;
    int cur_count = 0;
    int j = 0;

    for (char c : s) {
        if (c == ksa[j]) {
            cur_count++;

            if (++j == 3) {
                j = 0;
            }
        }
    }

    max_count = max(max_count, cur_count);
    cur_count = 0;
    j = 1;

    for (char c : s) {
        if (c == ksa[j]) {
            cur_count++;

            if (++j == 3) {
                j = 0;
            }
        }
    }

    if (cur_count == SIZE(s)) {
        cur_count--;
    }

    max_count = max(max_count, cur_count);
    cur_count = 0;
    j = 2;

    for (char c : s) {
        if (c == ksa[j]) {
            cur_count++;

            if (++j == 3) {
                j = 0;
            }
        }
    }

    if (cur_count >= SIZE(s) - 1) {
        cur_count = SIZE(s) - 2;
    }

    max_count = max(max_count, cur_count);
    cout << (SIZE(s) - max_count) * 2 << '\n';

    return 0;
}
