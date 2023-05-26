// Solve 2022-07-24
// Update 2023-05-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;

uint lengths[10000];

int main() {
    FASTIO;

    int k, n;
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> lengths[i];
    }

    uint low = 1, high = 2147483648;
    while (low + 1 < high) {
        uint mid = (low + high) >> 1;
        int mid_val = 0;

        for (int i = 0; i < k; i++) {
            mid_val += lengths[i] / mid;
        }

        if (mid_val >= n) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << low << '\n';

    return 0;
}
