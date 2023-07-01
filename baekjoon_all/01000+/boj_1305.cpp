// Solve 2023-07-01

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

    vector<int> kmp(n, 0);

    int i = 1, j = 0;
    while (i < n) {
        while (j > 0 && s[i] != s[j]) {
            j = kmp[j - 1];
        }
        if (s[i] == s[j]) {
            kmp[i] = ++j;
        }
        i++;
    }

    cout << n - kmp.back() << '\n';

    return 0;
}
