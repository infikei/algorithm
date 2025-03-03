// Solve 2025-03-02

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

void clamp_to_edge(int n, int m, int u, int v, vector<string> &texture) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cout << texture[min(x, u - 1)][min(y, v - 1)];
        }

        cout << '\n';
    }
}

void repeat(int n, int m, int u, int v, vector<string> &texture) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            cout << texture[x % u][y % v];
        }

        cout << '\n';
    }
}

void mirrored_repeat(int n, int m, int u, int v, vector<string> &texture) {
    int u2 = u * 2;
    int v2 = v * 2;

    for (int x = 0; x < n; x++) {
        int nx = x % u2;
        nx = min(nx, u2 - 1 - nx);

        for (int y = 0; y < m; y++) {
            int ny = y % v2;
            ny = min(ny, v2 - 1 - ny);

            cout << texture[nx][ny];
        }

        cout << '\n';
    }
}

int main() {
    FASTIO;

    int n, m, u, v;
    cin >> n >> m >> u >> v;

    vector<string> texture(u);

    for (string &row : texture) {
        cin >> row;
    }

    string cmd;
    cin >> cmd;

    if (cmd == "clamp-to-edge") {
        clamp_to_edge(n, m, u, v, texture);
    }
    else if (cmd == "repeat") {
        repeat(n, m, u, v, texture);
    }
    else {
        mirrored_repeat(n, m, u, v, texture);
    }

    return 0;
}
