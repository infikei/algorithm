// Solve 2023-08-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int level[5] = { 0, 300, 275, 250, 0 };

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for (int j = 1; j <= 4; j++) {
            if (x >= level[j]) {
                cout << j << ' ';
                break;
            }
        }
    }
    cout << '\n';

    return 0;
}
