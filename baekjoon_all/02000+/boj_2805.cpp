// Solve 2022-07-24
// Update 2023-05-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int trees[1000000];

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    int low = 0, high = 1000000001;
    while (low + 1 < high) {
        int mid = (low + high) >> 1;
        ll mid_val = 0;

        for (int i = 0; i < n; i++) {
            int tmp = trees[i] - mid;
            if (tmp > 0) {
                mid_val += tmp;
            }
        }

        if (mid_val >= m) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    cout << low << '\n';

    return 0;
}
