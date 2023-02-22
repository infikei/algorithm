// Solve 2023-02-22

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
#define INF (int)1e9
#define LLINF (ll)4e18
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

int main() {
    FASTIO;

    string a, b;
    cin >> a >> b;

    bigint aa = string_to_bigint(a);
    bigint bb = string_to_bigint(b);

    bigint ansans = bigint_add(aa, bb);
    string ans = bigint_to_string(ansans);
    cout << ans << '\n';

    return 0;
}