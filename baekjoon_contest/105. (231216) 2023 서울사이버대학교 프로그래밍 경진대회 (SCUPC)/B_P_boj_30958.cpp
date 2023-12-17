// Solve 2023-12-16

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
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);

    int abc_cnt[26] = { 0 };

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            abc_cnt[c - 'a']++;
        }
    }

    int max_abc_cnt = 0;

    for (int i = 0; i < 26; i++) {
        if (abc_cnt[i] > max_abc_cnt) {
            max_abc_cnt = abc_cnt[i];
        }
    }

    cout << max_abc_cnt << '\n';

    return 0;
}
