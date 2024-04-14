// Solve 2024-04-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string left;
    int right;
    cin >> left >> right;

    int min_eight_cnt = 0;

    for (char c : left) {
        if (c == '8') {
            min_eight_cnt++;
        }
    }

    for (int i = SIZE(left) - 1; i >= 0; i--) {
        if (left[i] != '8') continue;

        left[i] = '9';

        for (int j = i + 1; j < SIZE(left); j++) {
            left[j] = '0';
        }

        if (stoi(left) > right) break;

        min_eight_cnt--;
    }

    cout << min_eight_cnt << '\n';

    return 0;
}
