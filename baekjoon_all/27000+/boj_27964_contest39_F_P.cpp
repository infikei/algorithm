// Solve 2023-04-16

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

    int n;
    cin >> n;

    unordered_set<string> hs;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (SIZE(s) >= 6 && s.substr(SIZE(s) - 6, 6) == "Cheese") {
            hs.insert(s.substr(0, SIZE(s) - 6));
        }
    }

    if (SIZE(hs) >= 4) {
        cout << "yummy\n";
    }
    else {
        cout << "sad\n";
    }

    return 0;
}
