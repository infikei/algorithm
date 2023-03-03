// Solve 2022-08-26
// Update 2023-03-03

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

    int n = SIZE(s);
    vector<string> v;
    for (int i = 0; i < n; i++) {
        v.push_back(s.substr(i, n - i));
    }
    sort(ALL(v));

    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}