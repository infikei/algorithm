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
    string s;
    cin >> n >> s;

    int cnt[3] = { 0 };
    string bsa = "BSA";

    for (char c : s) {
        for (int i = 0; i < 3; i++) {
            if (c == bsa[i]) {
                cnt[i]++;
                break;
            }
        }
    }

    int max_cnt = 0;

    for (int i = 0; i < 3; i++) {
        if (cnt[i] > max_cnt) {
            max_cnt = cnt[i];
        }
    }

    string ans;

    for (int i = 0; i < 3; i++) {
        if (cnt[i] == max_cnt) {
            ans.push_back(bsa[i]);
        }
    }

    cout << (ans == "BSA" ? "SCU" : ans) << '\n';

    return 0;
}
