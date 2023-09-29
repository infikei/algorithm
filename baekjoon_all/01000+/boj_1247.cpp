// Solve 2022-11-06
// Update 2023-09-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct bigint{
    bool sign = false;
    string num = "0";

    bigint(string s = "0") {
        int pos = 0;

        if (s[pos] == '-') {
            sign = true;
            pos++;
        }
        else if (s[pos] == '+') {
            pos++;
        }

        while (pos < SIZE(s) && s[pos] == '0') {
            pos++;
        }

        if (pos == SIZE(s)) {
            num = "0";
            sign = false;
        }
        else {
            num = s.substr(pos, SIZE(s) - pos);
        }
    }
};

bool ubigint_lt(const string &a, const string &b) {
    if (SIZE(a) != SIZE(b)) return SIZE(a) < SIZE(b);

    for (int i = 0; i < SIZE(a); i++) {
        if (a[i] != b[i]) return a[i] < b[i];
    }

    return false;
}

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

string ubigint_sub(string a, string b) {
    if (a == b) return "0";

    if (ubigint_lt(a, b)) return ubigint_sub(b, a);

    string res;
    int sum = 0, carry = 0;

    while (!a.empty() || !b.empty() || carry) {
        sum = carry;

        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (!b.empty()) {
            sum -= b.back() - '0';
            b.pop_back();
        }

        if (sum < 0) {
            sum += 10;
            carry = -1;
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

bigint bigint_add(const bigint &a, const bigint &b) {
    bigint res;

    if (a.sign) {
        if (b.sign) {
            res.sign = true;
            res.num = ubigint_add(a.num, b.num);
        }
        else {
            res.sign = ubigint_lt(b.num, a.num);
            res.num = ubigint_sub(a.num, b.num);
        }
    }
    else {
        if (b.sign) {
            res.sign = ubigint_lt(a.num, b.num);
            res.num = ubigint_sub(a.num, b.num);
        }
        else {
            res.sign = false;
            res.num = ubigint_add(a.num, b.num);
        }
    }

    return res;
}

int main() {
    FASTIO;

    for (int ti = 0; ti < 3; ti++) {
        int n;
        cin >> n;

        bigint ans;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            ans = bigint_add(ans, bigint(s));
        }

        if (ans.num == "0") {
            cout << "0\n";
        }
        else if (ans.sign) {
            cout << "-\n";
        }
        else {
            cout << "+\n";
        }
    }

    return 0;
}
