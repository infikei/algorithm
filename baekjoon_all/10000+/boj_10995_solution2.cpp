// Solve 2022-10-01
// Update 2023-02-15

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

    string odd_line, even_line, tmp = " *";
    for (int i = 1; i <= n; i++) {
        even_line += tmp;
    }
    even_line += "\n";
    odd_line = even_line.substr(1);
    
    for (int i = 1; i <= n; i++) {
        cout << odd_line;
        i++;
        if (i <= n) {
            cout << even_line;
        }
    }

    return 0;
}