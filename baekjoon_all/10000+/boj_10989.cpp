// Solve 2023-02-23
// Update 2023-12-20

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    int num_cnt[10001] = { 0 };

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        num_cnt[num]++;
    }

    for (int num = 1; num <= 10000; num++) {
        int iter = num_cnt[num];

        while (--iter >= 0) {
            cout << num << '\n';
        }
    }

    return 0;
}
