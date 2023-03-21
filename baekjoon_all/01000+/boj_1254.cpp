// Solve 2022-09-14
// Update 2023-03-20

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

    string word;
    cin >> word;

    string word_rev = word;
    reverse(ALL(word_rev));

    int n = SIZE(word), max_same_length = 0;
    for (int len = 1; len <= n; len++) {
        if (word.substr(n - len, len) == word_rev.substr(0, len)) {
            max_same_length = len;
        }
    }

    int ans = n * 2 - max_same_length;
    cout << ans << '\n';

    return 0;
}
