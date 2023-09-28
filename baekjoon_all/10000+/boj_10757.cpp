// Solve 2022-08-04
// Update 2023-09-28

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
            sum += a.back() - '0';
            a.pop_back();
        }

        if (!b.empty()) {
            sum += b.back() - '0';
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

    while (SIZE(res) >= 2 && res.back() == '0') {
        res.pop_back();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    FASTIO;

    string a, b;
    cin >> a >> b;

    cout << ubigint_add(a, b) << '\n';

    return 0;
}
