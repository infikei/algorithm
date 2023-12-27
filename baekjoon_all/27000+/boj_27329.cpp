// Solve 2023-12-26

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

    bool ans = true;

    int i = 0, j = n / 2, i_end = n / 2;

    while (i < i_end) {
        if (s[i] != s[j]) {
            ans = false;
            break;
        }

        i++; j++;
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}
