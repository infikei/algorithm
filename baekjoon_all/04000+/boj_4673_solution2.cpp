// Solve 2022-06-03
// Update 2023-03-07

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

const int MAX_NUM = 10001;

int main() {
    FASTIO;

    bool ans[MAX_NUM] = {false};

    for (int num = 1; num < MAX_NUM; num++) {
        int next = num;
        string s = to_string(num);

        for (auto ch : s) {
            next += (ch - '0');
        }

        if (next < MAX_NUM) {
            ans[next] = true;
        }
    }

    for (int i = 1; i < MAX_NUM; i++) {
        if (!ans[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}