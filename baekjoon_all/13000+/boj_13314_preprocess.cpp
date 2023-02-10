// Solve 2023-01-29
// Update 2023-02-11

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int MAX = 101;
int n, a[MAX][MAX], d[MAX][MAX], e[MAX][MAX];

int main() {
    FASTIO;

    n = MAX - 1;

    // make a new graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) a[i][j] = 0;
            else if (i == n || j == n) a[i][j] = 1;
            else a[i][j] = 3;

            e[i][j] = d[i][j] = a[i][j];
        }
    }

    // wrong floyd-warshall
    for (int k = 1; k < n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}
    // correct floyd-warshall
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				e[i][j] = min(e[i][k] + e[k][j], e[i][j]);
			}
		}
	}

    // count the diff
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (d[i][j] != e[i][j]) cnt++;
		}
	}
    cout << cnt << '\n' << (cnt >= 9700 ? "PASS\n" : "NOT PASS\n");

    return 0;
}