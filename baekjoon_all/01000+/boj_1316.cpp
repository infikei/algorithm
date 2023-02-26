// Solve 2022-06-07
// Update 2023-02-26

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

    int n;
    cin >> n;
    int ans = n;

    bool check[26];

    for (int k = 0; k < n; k++) {
        string word;
        cin >> word;

        fill_n(check, 26, false);

        char ch = word[0];
        int i_end = SIZE(word);
        for (int i = 1; i < i_end; i++) {
            char ch2 = word[i];
            if (ch != ch2) {
                if (check[ch2 - 'a']) {
                    ans--;
                    break;
                }
                else {
                    check[ch - 'a'] = true;
                    ch = ch2;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}