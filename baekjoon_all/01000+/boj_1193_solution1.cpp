// Solve 2023-03-02

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

    int x;
    cin >> x;

    int line = 1, tmp = 1;
    while (tmp < x) {
        line++;
        tmp += line;
    }
    tmp -= line;

    int a = x - tmp;
    int b = line + 1 - a;
    if (line % 2 == 0) {
        cout << a << '/' << b << '\n';
    }
    else {
        cout << b << '/' << a << '\n';
    }

    return 0;
}