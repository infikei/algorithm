// Solve 2022-06-08
// Update 2024-02-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    int selected[8] = { 0 };

    for (int i = m; i < n; i++) {
        selected[i] = 1;
    }

    do {
        for (int i = 0; i < n; i++) {
            if (selected[i] == 0) {
                cout << i + 1 << ' ';
            }
        }

        cout << '\n';
    } while (next_permutation(selected, selected + n));

    return 0;
}
