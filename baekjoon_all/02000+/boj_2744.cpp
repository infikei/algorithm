// Solve 2022-07-23
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

    string line;
    cin >> line;

    int i_end = SIZE(line);
    for (int i = 0; i < i_end; i++) {
        char ch = line[i];
        if (ch >= 'a') {
            line[i] = ch - 'a' + 'A';
        }
        else {
            line[i] = ch - 'A' + 'a';
        }
    }
    cout << line << '\n';

    return 0;
}