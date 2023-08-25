// Solve 2023-02-15
// Update 2023-08-25

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int a[2], b[2], p[3];

    for (int i = 0; i < 2; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < 3; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < 3; i++) {
        int cnt = 0;

        for (int j = 0; j < 2; j++) {
            if ((p[i] - 1) % (a[j] + b[j]) < a[j]) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
