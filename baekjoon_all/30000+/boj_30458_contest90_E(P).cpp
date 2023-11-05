// Solve 2023-11-05

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

    int cnt[26] = { 0 };

    for (char c : s) {
        cnt[c - 'a']++;
    }

    if (n % 2 == 1) {
        cnt[s[n / 2] - 'a']--;
    }

    bool ans = true;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
