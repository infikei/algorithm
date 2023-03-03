// Solve 2022-11-06
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
    getline(cin, s);

    int i_end = SIZE(s);
    for (int i = 0; i < i_end; i++) {
        if (s[i] >= 'A' && s[i] <= 'M') {
            s[i] += 13;
        }
        else if (s[i] >= 'N' && s[i] <= 'Z') {
            s[i] -= 13;
        }
        else if (s[i] >= 'a' && s[i] <= 'm') {
            s[i] += 13;
        }
        else if (s[i] >= 'n' && s[i] <= 'z') {
            s[i] -= 13;
        }
    }
    cout << s << '\n';

    return 0;
}