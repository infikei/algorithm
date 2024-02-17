// Solve 2024-02-17

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int arr[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int same_cnt = 0;
    int different_idx = -1;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        if (arr[i] == i) {
            same_cnt++;
        }
        else {
            different_idx = i;
        }
    }

    cout << same_cnt << '\n';

    if (same_cnt == n) {
        cout << 2 << ' ';
        int iter = n - 1;

        while (iter-- > 0) {
            cout << 1 << ' ';
        }

        cout << '\n';
    }
    else {
        for (int i = 1; i <= n; i++) {
            cout << (arr[i] == i ? different_idx : arr[i]) << ' ';
        }

        cout << '\n';
    }

    return 0;
}
