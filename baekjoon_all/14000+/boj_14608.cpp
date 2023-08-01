// Solve 2023-08-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(9);

    int k;
    cin >> k;

    vector<int> c(k + 1, 0);
    for (int &ci : c) {
        cin >> ci;
    }

    int a, b, n;
    cin >> a >> b >> n;

    double delta_x = (double)(b - a) / n;

    cout << delta_x / 2 << '\n';

    return 0;
}
