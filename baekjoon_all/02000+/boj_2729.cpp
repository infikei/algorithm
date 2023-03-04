// Solve 2022-09-06
// Update 2023-03-04

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

string bin_add(string a, string b) {
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
        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }

        result = to_string(sum) + result;
    }

    if (result.find('1') != string::npos) {
        int idx = result.find('1');

        if (idx > 0) {
            int result_sz = result.length();
            result = result.substr(idx, result_sz - idx);
        }
    }
    else {
        result = "0";
    }

    return result;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        string bin0, bin1;
        cin >> bin0 >> bin1;

        cout << bin_add(bin0, bin1) << '\n';
    }

    return 0;
}