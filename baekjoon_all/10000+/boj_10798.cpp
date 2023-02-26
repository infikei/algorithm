// Solve 2022-08-14
// Update 2023-02-26

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

    string serolines[15];
    for (int i = 0; i < 5; i++) {
        string line;
        cin >> line;

        int j_end = SIZE(line);
        for (int j = 0; j < j_end; j++) {
            serolines[j].push_back(line[j]);
        }
    }

    for (int j = 0; j < 15; j++) {
        cout << serolines[j];
    }
    cout << '\n';

    return 0;
}