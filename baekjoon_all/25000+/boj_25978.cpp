// Solve 2025-03-12

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

int arr[1002][1002];
ll arr2[1002][1002];

void add_k_to_area(int x1, int y1, int x2, int y2, int k) {
    arr2[x1][y1] += k;
    arr2[x1][y2 + 1] -= k;
    arr2[x2 + 1][y1] -= k;
    arr2[x2 + 1][y2 + 1] += k;
}

void apply_imos(int n) {
    for (int x = 1; x <= n + 1; x++) {
        for (int y = 1; y <= n + 1; y++) {
            arr2[x][y] += arr2[x][y - 1] + arr2[x - 1][y] - arr2[x - 1][y - 1];
        }
    }

    for (int x = 1; x <= n + 1; x++) {
        for (int y = 1; y <= n + 1; y++) {
            arr2[x][y] += arr[x][y];
        }
    }
}

void apply_prefix_sum(int n) {
    for (int x = 1; x <= n + 1; x++) {
        for (int y = 1; y <= n + 1; y++) {
            arr2[x][y] += arr2[x][y - 1] + arr2[x - 1][y] - arr2[x - 1][y - 1];
        }
    }
}

ll get_area_sum(int x1, int y1, int x2, int y2) {
    return arr2[x2][y2] - arr2[x2][y1 - 1] - arr2[x1 - 1][y2] + arr2[x1 - 1][y1 - 1];
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            cin >> arr[x][y];
        }
    }

    int prev_cmd = 1;

    for (int i = 0; i < m; i++) {
        int cmd, x1, y1, x2, y2;
        cin >> cmd >> x1 >> y1 >> x2 >> y2;

        x1++; y1++; x2++; y2++;

        if (cmd == 1) {
            int k;
            cin >> k;

            add_k_to_area(x1, y1, x2, y2, k);
        }
        else if (cmd == 2) {
            if (prev_cmd == 1) {
                apply_imos(n);
                apply_prefix_sum(n);
                prev_cmd = 2;
            }

            cout << get_area_sum(x1, y1, x2, y2) << '\n';
        }
    }

    return 0;
}
