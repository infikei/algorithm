// Solve 2022-10-16
// Update 2023-03-14

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

    string s;
    cin >> s;

    string targets[2] = { "JOI", "IOI" };
    int cnt[2] = { 0, 0 };

    for (int i = 0; i < 2; i++) {
        int pos = s.find(targets[i]);
        while (pos != string::npos) {
            cnt[i]++;
            pos = s.find(targets[i], pos + 1);
        }
        cout << cnt[i] << '\n';
    }

    return 0;
}
