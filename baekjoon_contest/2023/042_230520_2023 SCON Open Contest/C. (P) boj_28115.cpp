// Solve 2023-05-20

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

int seq[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    bool ans = true;
    if (n >= 3) {
        int d = seq[1] - seq[0];
        for (int i = 2; i < n; i++) {
            if (seq[i] - seq[i - 1] != d) {
                ans = false;
                break;
            }
        }
    }

    if (ans) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
