// Solve 2022-07-18
// Update 2023-02-14

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

    string tmp = "*";
    for (int iter = n - 1; iter > 0; iter--) {
        cout << tmp << '\n';
        tmp += "*";
    }
    for (int iter = n - 1; iter > 0; iter--) {
        cout << tmp << '\n';
        tmp.pop_back();
    }
    cout << tmp << '\n';

    return 0;
}