#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
using bigint = pair<bool, string>;

bigint string_to_bigint(string s) {
    if (s == "-0") {
        s = "0";
    }
    if (s[0] == '-') {
        return { true, s.substr(1) };
    }
    return { false, s };
}

string bigint_to_string(bigint b) {
    if (b.first) {
        return "-" + b.second;
    }
    return b.second;
}

bool ubigint_lt(const string &a, const string &b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < (int)a.length(); i++) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    }
    return a.length() < b.length();
}

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

string ubigint_sub(string a, string b) {
    if (a == b) {
        return "0";
    }
    if (ubigint_lt(a, b)) {
        return ubigint_sub(b, a);
    }

    string result;
    int sum = 0, carry = 0;

    while (!a.empty() || !b.empty() || carry) {
        sum = carry;
        if (!a.empty()) {
            sum += (a.back() - '0');
            a.pop_back();
        }
        if (!b.empty()) {
            sum -= (b.back() - '0');
            b.pop_back();
        }
        if (sum < 0) {
            sum += 10;
            carry = -1;
        }
        else {
            carry = 0;
        }
        result.push_back('0' + sum);
    }

    // "00123"과 같이 맨 앞에 0이 포함되었을 경우 "123"과 같은 형태로 바꿔주기
    while (result[(int)result.length() - 1] == '0' && (int)result.length() >= 2) {
        result = result.substr(0, (int)result.length() - 1);
    }

    reverse(result.begin(), result.end());
    return result;
}

string ubigint_mul(string a, string b) {
    if (a == "0" || b == "0") {
        return "0";
    }

    string result, result2, a_copy, b_copy;
    int sum = 0, carry = 0, now = 0, zeros = 0;

    b_copy = b;
    result = "";
    while (!b_copy.empty()) {
        now = (b_copy.back() - '0');
        b_copy.pop_back();

        a_copy = a;
        result2 = "";
        while (!a_copy.empty() || carry) {
            sum = 0;
            if (!a_copy.empty()) {
                sum += (a_copy.back() - '0') * now;
                a_copy.pop_back();
            }
            sum += carry;
            carry = 0;
            while (sum >= 10) {
                sum -= 10;
                carry++;
            }
            result2.push_back('0' + sum);
        }

        reverse(result2.begin(), result2.end());
        for (int i = 0; i < zeros; i++) result2.push_back('0');
        zeros++;
        result = ubigint_add(result, result2);
    }

    return result;
}

string ubigint_pow(string a, int b) {
    if (b == 0) return "1";
    if (b == 1) return a;

    // 분할정복을 이용하여 빠르게 계산
    string k = ubigint_pow(a, b / 2);
    k = ubigint_mul(k, k);
    if (b % 2 == 1) k = ubigint_mul(k, a);
    return k;
}

bool bigint_lt(const bigint &a, const bigint &b) {
    if (a.first) {
        if (b.first) {
            return ubigint_lt(b.second, a.second);
        }
        else {
            return true;
        }
    }
    else {
        if (b.first) {
            return false;
        }
        else {
            return ubigint_lt(a.second, b.second);
        }
    }
}

bigint bigint_add(bigint a, bigint b) {
    if (a.first) {
        if (b.first) {
            return { true, ubigint_add(a.second, b.second) };
        }
        else {
            return { ubigint_lt(b.second, a.second), ubigint_sub(a.second, b.second) };
        }
    }
    else {
        if (b.first) {
            return { ubigint_lt(a.second, b.second), ubigint_sub(a.second, b.second) };
        }
        else {
            return { false, ubigint_add(a.second, b.second) };
        }
    }
}

bigint bigint_sub(bigint a, bigint b) {
    if (b.second == "0") {
        return a;
    }
    b.first = !b.first;
    return bigint_add(a, b);
}

bigint bigint_mul(bigint a, bigint b) {
    if (a.second == "0" || b.second == "0") {
        return { false, "0" };
    }
    if (a.first == b.first) {
        return { false, ubigint_mul(a.second, b.second) };
    }
    else {
        return { true, ubigint_mul(a.second, b.second) };
    }
}

int main() {
    FASTIO;

    // 예제 : 300! 계산하기
    int n = 300;

    bigint fac = string_to_bigint("1");
    for (int i = 1; i <= n; i++) {
        bigint ii = string_to_bigint(to_string(i));
        fac = bigint_mul(fac, ii);
    }

    cout << n << "! = " << bigint_to_string(fac) << '\n';

    return 0;
}