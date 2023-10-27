// Solve 2023-10-26

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
        int tii;
        cin >> tii;

        int arr[20];

        for (int i = 0; i < 20; i++) {
            cin >> arr[i];
        }

        int ans = 0;

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i]) ans++;
            }
        }

        cout << tii << ' ' << ans << '\n';
    }

    return 0;
}
