// Solve 2023-04-23

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

    while (true) {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == "0" && s2 == "0") {
            break;
        }

        int ans = 0;
        int carry = 0;

        while (!s1.empty() && !s2.empty()) {
            int n1 = s1.back() - '0';
            int n2 = s2.back() - '0';
            s1.pop_back();
            s2.pop_back();

            carry += n1;
            carry += n2;
            carry /= 10;
            if (carry > 0) {
                ans++;
            }
        }

        while (!s1.empty()) {
            int n1 = s1.back() - '0';
            s1.pop_back();

            carry += n1;
            carry /= 10;
            if (carry > 0) {
                ans++;
            }
        }

        while (!s2.empty()) {
            int n2 = s2.back() - '0';
            s2.pop_back();

            carry += n2;
            carry /= 10;
            if (carry > 0) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
