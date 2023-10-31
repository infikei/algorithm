// Solve 2023-10-31

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, max_weight;
    cin >> n >> max_weight;

    int box = 0, cur_weight = 0;

    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;

        if (cur_weight + weight > max_weight) {
            box++;
            cur_weight = weight;
        }
        else {
            cur_weight += weight;
        }
    }

    if (cur_weight > 0) {
        box++;
        cur_weight = 0;
    }

    cout << box << '\n';

    return 0;
}
