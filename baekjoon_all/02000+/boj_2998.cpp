// Solve 2022-12-21
// Update 2023-08-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string bin_num, oct_num;
    cin >> bin_num;

    int r = SIZE(bin_num) % 3;

    if (r == 2) {
        oct_num.push_back((bin_num[0] - '0') * 2 + bin_num[1]);
    }
    else if (r == 1) {
        oct_num.push_back(bin_num[0]);
    }

    for (int i = r, ie = SIZE(bin_num); i < ie; i += 3) {
        oct_num.push_back((bin_num[i] - '0') * 4 + (bin_num[i + 1] - '0') * 2 + bin_num[i + 2]);
    }

    cout << oct_num << '\n';

    return 0;
}
