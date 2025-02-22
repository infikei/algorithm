// Solve 2023-10-31
// Update 2025-02-21

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    FASTIO;

    int n, max_weight;
    cin >> n >> max_weight;

    int box_cnt = 0;
    int cur_weight = 0;

    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;

        if (cur_weight + weight > max_weight) {
            box_cnt++;
            cur_weight = weight;
        }
        else {
            cur_weight += weight;
        }
    }

    if (cur_weight > 0) {
        box_cnt++;
        cur_weight = 0;
    }

    cout << box_cnt << '\n';

    return 0;
}
