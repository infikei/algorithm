// Solve 2023-12-19

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int k;
        cin >> k;

        vector<int> ans;

        while (k > 0) {
            ans.push_back(k % 3);
            k /= 3;
        }

        for (auto it = ans.rbegin(); it != ans.rend(); it++) {
            cout << *it << ' ';
        }

        cout << '\n';
    }

    return 0;
}
