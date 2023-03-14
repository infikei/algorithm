// Solve 2022-11-04
// Update 2023-03-14

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

    int v;
    cin >> v;

    string votes;
    cin >> votes;

    int cnt[2] = { 0 };
    for (auto ch : votes) {
        cnt[ch - 'A']++;
    }

    if (cnt[0] > cnt[1]) {
        cout << "A\n";
    }
    else if (cnt[0] < cnt[1]) {
        cout << "B\n";
    }
    else {
        cout << "Tie\n";
    }

    return 0;
}
