// Solve 2023-05-28

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

ll oct_to_decimal(const string &s) {
    ll n = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        n <<= 3;
        n += (*it) - '0';
    }

    return n;
}

string decimal_to_oct(ll n) {
    if (n == 0) return "0";

    bool sign = false;
    if (n < 0) {
        sign = true;
        n = -n;
    }

    string s;
    while (n > 0) {
        char ch = ('0' + (n % 8));
        s = ch + s;
        n >>= 3;
    }

    if (sign) s = '-' + s;
    return s;
}

int main() {
    FASTIO;

    string s;
    cin >> s;

    string a_oct, b_oct;
    bool a_sign = false, b_sign = false;

    int cur = 0;
    if (s[0] == '-') {
        a_sign = true;
        cur++;
    }

    while (true) {
        if (s[cur] >= '0' && s[cur] <= '9') {
            a_oct.push_back(s[cur]);
            cur++;
            continue;
        }
        break;
    }

    char op = s[cur];
    cur++;

    if (s[cur] == '-') {
        b_sign = true;
        cur++;
    }

    while (cur < SIZE(s)) {
        b_oct.push_back(s[cur]);
        cur++;
    }

    ll a = oct_to_decimal(a_oct);
    ll b = oct_to_decimal(b_oct);
    if (a_sign) a = -a;
    if (b_sign) b = -b;

    ll ans = 0;
    bool valid = true;
    if (op == '+') ans = a + b;
    else if (op == '-') ans = a - b;
    else if (op == '*') ans = a * b;
    else if (b == 0) valid = false;
    else ans = (int)(floor((double)a / b));

    if (!valid) {
        cout << "invalid\n";
    }
    else {
        string ans_oct = decimal_to_oct(ans);
        cout << ans_oct << '\n';
    }

    return 0;
}
