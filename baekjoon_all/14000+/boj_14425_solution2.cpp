// Solve 2022-06-03
// Update 2023-03-23

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

string words[10000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    sort(words, words + n);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (binary_search(words, words + n, tmp)) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
