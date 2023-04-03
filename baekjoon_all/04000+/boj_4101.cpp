// Solve 2022-09-14
// Update 2023-04-02

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

    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }

        if (a > b) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}
