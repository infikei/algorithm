// Solve 2022-09-09
// Update 2023-09-03

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
        int p;
        cin >> p;

        int max_price;
        string max_name;
        cin >> max_price >> max_name;

        for (int pi = 1; pi < p; pi++) {
            int price;
            string name;
            cin >> price >> name;

            if (price > max_price) {
                max_price = price;
                max_name = name;
            }
        }

        cout << max_name << '\n';
    }

    return 0;
}
