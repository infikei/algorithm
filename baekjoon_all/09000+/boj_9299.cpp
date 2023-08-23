// Solve 2023-08-22

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

    for (int ti = 1; ti <= t; ti++) {
        int n, a;
        cin >> n;

        vector<int> vec;

        for (int i = n; i >= 0; i--) {
            cin >> a;

            vec.push_back(a * i);
        }

        vec.pop_back();

        cout << "Case " << ti << ": " << n - 1 << ' ';

        for (const int &num : vec) {
            cout << num << ' ';
        }

        cout << '\n';
    }

    return 0;
}
