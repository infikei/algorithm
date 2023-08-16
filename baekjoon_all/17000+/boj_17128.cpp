// Solve 2022-09-06
// Update 2023-08-16

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int cow[200000];

int main() {
    FASTIO;

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }

    int ans = 0;

    for (int i = 0; i < n - 3; i++) {
        ans += cow[i] * cow[i + 1] * cow[i + 2] * cow[i + 3];
    }
    ans += cow[n - 3] * cow[n - 2] * cow[n - 1] * cow[0];
    ans += cow[n - 2] * cow[n - 1] * cow[0] * cow[1];
    ans += cow[n - 1] * cow[0] * cow[1] * cow[2];

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;

        int part = 0;
        for (int i = x - 3; i <= x; i++) {
            if (i >= 0 && i < n - 3) {
                part += cow[i] * cow[i + 1] * cow[i + 2] * cow[i + 3];
            }
            else if (i == -3 || i == n - 3) {
                part += cow[n - 3] * cow[n - 2] * cow[n - 1] * cow[0];
            }
            else if (i == -2 || i == n - 2) {
                part += cow[n - 2] * cow[n - 1] * cow[0] * cow[1];
            }
            else {
                part += cow[n - 1] * cow[0] * cow[1] * cow[2];
            }
        }

        ans = ans - part * 2;
        cow[x] *= -1;

        cout << ans << '\n';
    }

    return 0;
}
