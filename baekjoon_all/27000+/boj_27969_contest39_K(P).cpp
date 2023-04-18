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

    string line;
    getline(cin, line);

    int ans = 0;

    stringstream ss(line);
    string w;
    while (getline(ss, w, ' ')) {
        if (w == "[") {
            ans += 8;
        }
        else if (w == "]") {
            continue;
        }
        else if (isdigit(w[0])) {
            ans += 8;
        }
        else {
            ans += SIZE(w) + 12;
        }
    }

    cout << ans << '\n';

    return 0;
}
