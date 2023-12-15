// Solve 2022-11-04
// Update 2023-12-15

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int v;
    string votes;
    cin >> v >> votes;

    int cnt[2] = { 0 };

    for (char c : votes) {
        cnt[c - 'A']++;
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
