// Solve 2023-10-01
// Update 2023-10-09

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

    unordered_map<string, int> tunnel_in;

    for (int i = 0; i < n; i++) {
        string car;
        cin >> car;

        tunnel_in[car] = i;
    }

    vector<int> tunnel_out(n);

    for (int i = 0; i < n; i++) {
        string car;
        cin >> car;

        tunnel_out[i] = tunnel_in[car];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tunnel_out[i] > tunnel_out[j]) {
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
