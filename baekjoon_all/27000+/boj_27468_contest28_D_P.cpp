// Solve 2023-02-11

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    cout << "YES\n";
    int n4 = n % 4;
    if (n4 == 3) {
        int i = 4;
        for (; i < n; i += 4) {
            cout << i - 2 << ' ' << i - 3 << ' ' << i - 1 << ' ' << i << ' ';
        }
        cout << i - 2 << ' ' << i - 3 << ' ' << i - 1 << '\n';
    }
    else {
        int i = 4;
        for (; i < n; i += 4) {
            cout << i - 3 << ' ' << i - 2 << ' ' << i << ' ' << i - 1 << ' ';
        }
        if (n4 == 1) {
            cout << i - 3 << '\n';
        }
        else if (n4 == 2) {
            cout << i - 3 << ' ' << i - 2 << '\n';
        }
        else {
            cout << i - 3 << ' ' << i - 2 << ' ' << i << ' ' << i - 1 << '\n';
        }
    }

    return 0;
}