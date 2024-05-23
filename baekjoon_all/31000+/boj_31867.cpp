// Solve 2024-05-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    string k;
    cin >> n >> k;

    int cnt[2] = { 0 };

    for (char c : k) {
        cnt[(c - '0') & 1]++;
    }

    if (cnt[0] > cnt[1]) {
        cout << 0 << '\n';
    }
    else if (cnt[0] < cnt[1]) {
        cout << 1 << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
