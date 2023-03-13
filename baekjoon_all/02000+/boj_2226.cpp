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

string ubigint_add(string a, string b) {
    string result;
    int sum = 0, carry = 0;

    while (!a.empty() || !b.empty() || carry) {
        sum = carry;
        if (!a.empty()) {
            sum += (a.back() - '0');
            a.pop_back();
        }
        if (!b.empty()) {
            sum += (b.back() - '0');
            b.pop_back();
        }
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result.push_back('0' + sum);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<string> dp = { "0", "0", "1" };
    for (int i = 3; i <= n; i++) {
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = ubigint_add(ubigint_add(dp[0], dp[0]), dp[1]);
    }

    if (n == 1) {
        cout << 0 << '\n';
    }
    else {
        cout << dp[2] << '\n';
    }

    return 0;
}
