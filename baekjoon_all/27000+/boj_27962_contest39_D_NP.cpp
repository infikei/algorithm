// Solve 2023-04-17

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

    string s;
    cin >> s;

    bool ans = false;
    for (int i = 1; i < n; i++) {
        string s2 = s.substr(0, i);
        string s3 = s.substr(n - i, i);

        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (s2[j] != s3[j]) {
                cnt++;
                if (cnt > 1) {
                    break;
                }
            }
        }

        if (cnt == 1) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
