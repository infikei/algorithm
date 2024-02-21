// Solve 2024-02-21

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

    int cnt[2] = { 0 };

    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cnt[0]++;
        }
        else if (c == 'y') {
            cnt[1]++;
        }
    }

    cnt[1] += cnt[0];
    cout << cnt[0] << ' ' << cnt[1] << '\n';

    return 0;
}
