// Solve 2023-01-15
// Update 2023-03-20

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

    string a, b;
    cin >> a >> b;

    string ans;
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
        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }
        ans = to_string(sum) + ans;
    }

    if (ans.find('1') == string::npos) {
        ans = "0";
    }
    else {
        int idx = ans.find('1');
        if (idx > 0) {
            ans = ans.substr(idx);
        }
    }

    cout << ans << '\n';

    return 0;
}
