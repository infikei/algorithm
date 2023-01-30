#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int N_MAX = 20;
int n, ans;
int costs[N_MAX][N_MAX];
bool removed_routes[N_MAX][N_MAX], is_possible;

void floyd_warshall() {
    is_possible = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (costs[j][k] > costs[j][i] + costs[i][k]) {
                    is_possible = false;
                    return;
                }
                else if (costs[j][k] == costs[j][i] + costs[i][k]) {
                    removed_routes[j][k] = true;
                }
            }
        }
    }
}

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costs[i][j];
        }
    }

    floyd_warshall();

    if (is_possible) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (!removed_routes[i][j]) {
                    ans += costs[i][j];
                }
            }
        }
    }
    else ans = -1;

    cout << ans << '\n';

    return 0;
}