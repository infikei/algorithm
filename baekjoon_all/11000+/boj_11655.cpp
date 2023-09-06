// Solve 2022-11-06
// Update 2023-09-06

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string line;
    getline(cin, line);

    for (int i = 0, ie = SIZE(line); i < ie; i++) {
        if (line[i] >= 'A' && line[i] <= 'M' || line[i] >= 'a' && line[i] <= 'm') {
            line[i] += 13;
        }
        else if (line[i] >= 'N' && line[i] <= 'Z' || line[i] >= 'n' && line[i] <= 'z') {
            line[i] -= 13;
        }
    }

    cout << line << '\n';

    return 0;
}
