// Solve 2023-12-21

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
    string s;
    cin >> n >> s;

    int cnt[2] = { 0 };

    for (char c : s) {
        if (c == '2') cnt[0]++;
        else cnt[1]++;
    }

    if (cnt[0] > cnt[1]) cout << "2\n";
    else if (cnt[0] < cnt[1]) cout << "e\n";
    else cout << "yee\n";

    return 0;
}
