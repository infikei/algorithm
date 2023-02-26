// Solve 2022-06-05
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

    string input;
    cin >> input;

    int ans[26];
    fill_n(ans, 26, -1);

    for (int i = 0; i < input.size(); i++) {
        if (ans[input[i] - 'a'] == -1)
            ans[input[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}