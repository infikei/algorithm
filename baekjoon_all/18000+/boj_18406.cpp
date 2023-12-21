// Solve 2023-01-15
// Update 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string n;
    cin >> n;

    int left_sum = 0;
    int right_sum = 0;

    for (int i = 0, i_end = SIZE(n) / 2; i < i_end; i++) {
        left_sum += n[i] - '0';
    }

    for (int i = SIZE(n) / 2, i_end = SIZE(n); i < i_end; i++) {
        right_sum += n[i] - '0';
    }

    cout << (left_sum == right_sum ? "LUCKY" : "READY") << '\n';

    return 0;
}
