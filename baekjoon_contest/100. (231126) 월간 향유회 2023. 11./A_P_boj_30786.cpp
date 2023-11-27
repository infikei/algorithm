// Solve 2023-11-26

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

    vector<int> even;
    vector<int> odd;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        if ((x + y) % 2 == 0) {
            even.push_back(i);
        }
        else {
            odd.push_back(i);
        }
    }

    if (SIZE(even) == 0 || SIZE(odd) == 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        for (int i : even) {
            cout << i << ' ';
        }

        for (int i : odd) {
            cout << i << ' ';
        }

        cout << '\n';
    }

    return 0;
}
