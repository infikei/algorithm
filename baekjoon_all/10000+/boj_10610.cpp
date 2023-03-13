// Solve 2023-03-13

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

    string n;
    cin >> n;

    bool check = true;

    int tmp = 0;
    for (auto ch : n) {
        tmp += ch - '0';
    }
    if (tmp % 3 != 0) {
        check = false;
    }

    if (check) {
        sort(ALL(n), greater<>());
        if (n.back() != '0') {
            check = false;
        }
    }

    if (check) {
        cout << n << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}
