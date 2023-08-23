// Solve 2023-01-10
// Update 2023-08-23

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
        if (line == "#") break;

        int quick_sum = 0, iter = 0;

        for (const char c : line) {
            iter++;
            if (c == ' ') continue;
            quick_sum += iter * (c - 'A' + 1);
        }

        cout << quick_sum << '\n';
    }

    return 0;
}
