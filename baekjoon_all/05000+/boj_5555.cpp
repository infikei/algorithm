// Solve 2023-04-08

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

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string ring;
        cin >> ring;
        ring += ring;

        for (int j = 0; j < 10; j++) {
            if (ring.substr(j, SIZE(word)) == word) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
