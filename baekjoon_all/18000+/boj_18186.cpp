// Solve 2023-06-01
// Update 2024-02-14

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int ramen[1000002];

int main() {
    FASTIO;

    int n;
    ll b, c;
    cin >> n >> b >> c;
    ll bc = b + c;
    ll bcc = bc + c;

    for (int i = 0; i < n; i++) {
        cin >> ramen[i];
    }

    ll cost = 0;

    if (b <= c) {
        for (int i = 0; i < n; i++) {
            cost += ramen[i];
        }

        cost *= b;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (ramen[i + 1] > ramen[i + 2]) {
                int cur_ramen = min(ramen[i], ramen[i + 1] - ramen[i + 2]);
                ramen[i] -= cur_ramen;
                ramen[i + 1] -= cur_ramen;
                cost += cur_ramen * bc;
            }

            int cur_ramen = min(ramen[i], min(ramen[i + 1], ramen[i + 2]));
            ramen[i] -= cur_ramen;
            ramen[i + 1] -= cur_ramen;
            ramen[i + 2] -= cur_ramen;
            cost += cur_ramen * bcc;

            cost += ramen[i] * b;
        }
    }

    cout << cost << '\n';

    return 0;
}
