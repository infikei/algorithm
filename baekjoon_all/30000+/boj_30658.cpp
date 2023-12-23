// Solve 2023-12-23

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
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> vec(n);

        for (int &x : vec) {
            cin >> x;
        }

        reverse(vec.begin(), vec.end());

        for (int &x : vec) {
            cout << x << '\n';
        }

        cout << 0 << '\n';
    }

    return 0;
}
