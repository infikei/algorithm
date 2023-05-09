// Solve 2023-05-09

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

    int n, m;
    cin >> n >> m;

    vector<int> vec;
    vector<string> vec2;

    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;

        if (!vec.empty() && vec.back() == x) {
            continue;
        }
        vec.push_back(x);
        vec2.push_back(s);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int pos = lower_bound(ALL(vec), x) - vec.begin();
        cout << vec2[pos] << '\n';
    }

    return 0;
}
