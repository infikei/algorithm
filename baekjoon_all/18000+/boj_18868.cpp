// Solve 2025-05-14

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

int planet[10][100];

int main() {
    FASTIO;

    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> planet[i][j];
        }
    }

    int equivalent_cnt = 0;

    for (int a = 0; a < m; a++) {
        for (int b = a + 1; b < m; b++) {
            bool equivalent_flag = true;

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int a_universe = (planet[a][i] < planet[a][j] ? -1 : (planet[a][i] > planet[a][j] ? 1 : 0));
                    int b_universe = (planet[b][i] < planet[b][j] ? -1 : (planet[b][i] > planet[b][j] ? 1 : 0));

                    if (a_universe != b_universe) {
                        equivalent_flag = false;
                        break;
                    }
                }

                if (!equivalent_flag) break;
            }

            if (equivalent_flag) equivalent_cnt++;
        }
    }

    cout << equivalent_cnt << '\n';

    return 0;
}
