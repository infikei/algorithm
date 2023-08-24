// Solve 2022-11-07
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string long_name;
    cin >> long_name;

    string short_name;
    short_name.push_back(long_name[0]);

    for (int i = 1, ie = SIZE(long_name); i < ie; i++) {
        if (long_name[i] == '-') {
            short_name.push_back(long_name[i + 1]);
        }
    }

    cout << short_name << '\n';

    return 0;
}
