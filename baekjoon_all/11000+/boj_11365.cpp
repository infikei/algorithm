// Solve 2022-11-12
// Update 2023-09-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    while (true) {
        string line;
        getline(cin, line);
        if (line == "END") break;

        reverse(line.begin(), line.end());

        cout << line << '\n';
    }

    return 0;
}
