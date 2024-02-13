// Solve 2023-01-15
// Update 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int n;
int seq[8];

void recur(int depth = 0, int selected = 0) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            cout << seq[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if ((selected & 1 << i) == 0) {
            seq[depth] = i;
            recur(depth + 1, selected | 1 << i);
        }
    }
}

int main() {
    FASTIO;

    cin >> n;

    recur();

    return 0;
}
