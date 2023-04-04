// Solve 2023-04-03

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

inline int time_to_sec(string s) {
    int res = 0;
    stringstream ss(s);
    string w;
    for (int i = 0; i < 3; i++) {
        getline(ss, w, ':');
        res *= 60;
        res += stoi(w);
    }
    return res;
}

int main() {
    FASTIO;

    int c, h;
    cin >> c >> h;

    int t[1200];
    c += h;
    for (int i = 0; i < c; i++) {
        string s;
        cin >> s;
        t[i] = time_to_sec(s);
    }
    sort(t, t + c);

    int ans = 86400 - 40;
    for (int i = 1; i < c; i++) {
        ans -= min(40, t[i] - t[i - 1]);
    }
    cout << ans << '\n';

    return 0;
}
