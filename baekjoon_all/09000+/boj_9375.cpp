// Solve 2022-06-08
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

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        unordered_map<string, int> clothes_type_cnt;

        for (int i = 0; i < n; i++) {
            string clothes_name, clothes_type;
            cin >> clothes_name >> clothes_type;

            clothes_type_cnt[clothes_type]++;
        }

        int ans = 1;

        for (auto it = clothes_type_cnt.begin(); it != clothes_type_cnt.end(); it++) {
            ans *= it->second + 1;
        }

        cout << --ans << '\n';
    }

    return 0;
}
