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

string bigint_to_string(bigint b) {
    if (b.sign) return "-" + b.num;
    else return b.num;
}

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

string ubigint_mul(const string &a, const string &b) {
    if (a == "0" || b == "0") return "0";

    string res, b_copy = b;
    int zeros = 0;

    while (!b_copy.empty()) {
        int now = b_copy.back() - '0';
        b_copy.pop_back();

        string res2 = "", a_copy = a;
        int sum = 0, carry = 0;

        while (!a_copy.empty() || carry) {
            sum = carry;

            if (!a_copy.empty()) {
                sum += (a_copy.back() - '0') * now;
                a_copy.pop_back();
            }

            carry = sum / 10;
            sum %= 10;

            res2.push_back('0' + sum);
        }

        reverse(res2.begin(), res2.end());

        for (int i = 0; i < zeros; i++) {
            res2.push_back('0');
        }

        zeros++;
        res = ubigint_add(res, res2);
    }

    return res;
}

string ubigint_pow(const string &a, int b) {
    if (b == 0) return "1";
    if (b == 1) return a;

    string res = "1", aa = a;

    while (b > 0) {
        if (b & 1) {
            res = ubigint_mul(res, aa);
        }

        aa = ubigint_mul(aa, aa);
        b >>= 1;
    }

    return res;
}

bool bigint_lt(const bigint &a, const bigint &b) {
    if (a.sign) {
        if (b.sign) {
            return ubigint_lt(b.num, a.num);
        }
        else {
            return true;
        }
    }
    else {
        if (b.sign) {
            return false;
        }
        else {
            return ubigint_lt(a.num, b.num);
        }
    }
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

bigint bigint_sub(const bigint &a, bigint b) {
    if (b.num == "0") return a;

    b.sign = !b.sign;

    return bigint_add(a, b);
}

bigint bigint_mul(const bigint &a, const bigint &b) {
    bigint res;

    if (a.num == "0" || b.num == "0") {
        res.sign = false;
        res.num = "0";
    }
    if (a.sign == b.sign) {
        res.sign = false;
        res.num = ubigint_mul(a.num, b.num);
    }
    else {
        res.sign = true;
        res.num = ubigint_mul(a.num, b.num);
    }

    return res;
}

bigint bigint_pow(const bigint &a, int b) {
    bigint res;

    res.num = ubigint_pow(a.num, b);

    if (a.sign && b % 2 != 0) res.sign = true;
    else res.sign = false;

    return res;
}

int main() {
    FASTIO;

    cout << ubigint_add("123456789123456789", "876543210876543210") << '\n';
    cout << ubigint_sub("987654321987654321", "876543210876543210") << '\n';
    cout << ubigint_mul("1024", "1048576") << '\n';
    cout << ubigint_pow("2", 32) << '\n';

    cout << bigint_to_string(bigint_pow(bigint("-002"), 31)) << '\n';
    cout << bigint_to_string(bigint_pow(bigint("-002"), 32)) << '\n';

    // 예제 : 300! 계산하기

    bigint res("1");

    for (int i = 1; i <= 300; i++) {
        bigint ii(to_string(i));

        res = bigint_mul(res, ii);
    }

    cout << "300! = " << bigint_to_string(res) << '\n';

    return 0;
}
