// Solve 2023-03-26

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

    cout << "YES\n";

    // bi 출력
    for (int i = n - 1; i > 0; i -= 2) {
        cout << i << ' ';
    }
    cout << n << ' ';
    for (int i = ((n - 1) % 2) + 1; i < n; i += 2) {
        cout << i << ' ';
    }
    cout << '\n';

    // ci 출력
    for (int i = 1, i_end = n / 2; i <= i_end; i++) {
        cout << i << ' ' << n + 1 - i << ' ';
    }
    if (n % 2 == 1) {
        cout << n / 2 + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
