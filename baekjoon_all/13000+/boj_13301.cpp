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

    int n;
    cin >> n;

    vector<ll> fibonacci_numbers(n + 1);
    fibonacci_numbers[0] = fibonacci_numbers[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibonacci_numbers[i] = fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1];
    }

    ll ans = (fibonacci_numbers[n] + fibonacci_numbers[n - 1]) * 2;
    cout << ans << '\n';

    return 0;
}