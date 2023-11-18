// Solve 2023-11-17

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

    vector<int> vec;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());

    int q_idx = 0;

    while (q_idx < n) {
        if (vec[n - q_idx - 1] <= q_idx && (q_idx == 0 || vec[n - q_idx] >= q_idx)) {
            break;
        }

        q_idx++;
    }

    cout << q_idx << '\n';

    return 0;
}
