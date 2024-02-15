// Solve 2022-06-03
// Update 2024-02-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a, b, c;
    cin >> a >> b >> c;

    string abc = to_string(a * b * c);
    int digit_cnt[10] = { 0 };

    for (char d : abc) {
        digit_cnt[d - '0']++;
    }

    for (int d : digit_cnt) {
        cout << d << '\n';
    }

    return 0;
}
