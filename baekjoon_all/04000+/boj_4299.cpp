// Solve 2022-11-06
// Update 2023-02-08

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int sum, diff, score[2];
    cin >> sum >> diff;

    score[0] = (sum + diff) / 2;
    score[1] = (sum - diff) / 2;
    if (score[0] < 0 || score[1] < 0 || score[0] + score[1] != sum || score[0] - score[1] != diff) {
        cout << -1 << '\n';
    }
    else {
        cout << score[0] << ' ' << score[1] << '\n';
    }

    return 0;
}