#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

const int N_MAX = 1000, M_MAX = 1000;
int n, m;
ll p[N_MAX][M_MAX], f[N_MAX], dist_sum;

int main() {
    fastio;

    cin >> n >> m;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sort(p[i], p[i] + m);
        f[i] = p[i][m / 2];
        for (int j = 0; j < m; j++) {
            dist_sum += abs(f[i] - p[i][j]);
        }
    }

    cout << dist_sum << '\n';
    for (int i = 0; i < n; i++) {
        cout << f[i] << ' ';
    }
    cout << '\n';

    return 0;
}