// Solve 2022-11-10
// Update 2023-07-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

string ubigint_add(string a, string b) {
    string res;
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

        res.push_back('0' + sum);
    }

    reverse(res.begin(), res.end());

    return res;
}

string calc_big_fibonacci(int k) {
    if (k == 0) return "0";

    string f_val[3] = { "0", "0", "1" };
    for (int i = 2; i <= k; i++) {
        f_val[0] = f_val[1];
        f_val[1] = f_val[2];
        f_val[2] = ubigint_add(f_val[0], f_val[1]);
    }

    return f_val[2];
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    cout << calc_big_fibonacci(n) << '\n';

    return 0;
}
