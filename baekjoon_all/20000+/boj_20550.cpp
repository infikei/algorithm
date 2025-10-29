// Solve 2025-10-29

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int n, k, q;
int arr[500000];
ll fenwick[500000];

void update_fenwick(int x, ll diff) {
    for (int a = x; a <= n; a += (a & -a)) {
        fenwick[a - 1] += diff;
    }
}

ll get_from_fenwick(int x) {
    ll ret = 0;

    for (int a = x; a >= 1; a -= (a & -a)) {
        ret += fenwick[a - 1];
    }

    return ret;
}

void update_fenwick_2d(int x, int y, ll diff) {
    for (int a = x; a <= n; a += (a & -a)) {
        for (int b = y; b <= n; b += (b & -b)) {
            int idx2 = (a - 1) * n + (b - 1);
            fenwick[idx2] += diff;
        }
    }
}

ll get_from_fenwick_2d(int x, int y) {
    ll ret = 0;

    for (int a = x; a >= 1; a -= (a & -a)) {
        for (int b = y; b >= 1; b -= (b & -b)) {
            int idx2 = (a - 1) * n + (b - 1);
            ret += fenwick[idx2];
        }
    }

    return ret;
}

void update_fenwick_3d(int x, int y, int z, ll diff) {
    for (int a = x; a <= n; a += (a & -a)) {
        for (int b = y; b <= n; b += (b & -b)) {
            int idx2 = (a - 1) * n + (b - 1);

            for (int c = z; c <= n; c += (c & -c)) {
                int idx3 = idx2 * n + (c - 1);
                fenwick[idx3] += diff;
            }
        }
    }
}

ll get_from_fenwick_3d(int x, int y, int z) {
    ll ret = 0;

    for (int a = x; a >= 1; a -= (a & -a)) {
        for (int b = y; b >= 1; b -= (b & -b)) {
            int idx2 = (a - 1) * n + (b - 1);

            for (int c = z; c >= 1; c -= (c & -c)) {
                int idx3 = idx2 * n + (c - 1);
                ret += fenwick[idx3];
            }
        }
    }

    return ret;
}

void update_fenwick_4d(int x, int y, int z, int w, ll diff) {
    for (int a = x; a <= n; a += (a & -a)) {
        for (int b = y; b <= n; b += (b & -b)) {
            int idx2 = (a - 1) * n + (b - 1);

            for (int c = z; c <= n; c += (c & -c)) {
                int idx3 = idx2 * n + (c - 1);

                for (int d = w; d <= n; d += (d & -d)) {
                    int idx4 = idx3 * n + (d - 1);
                    fenwick[idx4] += diff;
                }
            }
        }
    }
}

ll get_from_fenwick_4d(int x, int y, int z, int w) {
    ll ret = 0;

    for (int a = x; a >= 1; a -= (a & -a)) {
        for (int b = y; b >= 1; b -= (b & -b)) {
            int idx2 = (a - 1) * n + (b - 1);

            for (int c = z; c >= 1; c -= (c & -c)) {
                int idx3 = idx2 * n + (c - 1);

                for (int d = w; d >= 1; d -= (d & -d)) {
                    int idx4 = idx3 * n + (d - 1);
                    ret += fenwick[idx4];
                }
            }
        }
    }

    return ret;
}

void solution() {
    for (int x = 1; x <= n; x++) {
        int v;
        cin >> v;
        arr[x - 1] = v;
        update_fenwick(x, v);
    }

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x1, x2;
            cin >> x1 >> x2;
            cout << get_from_fenwick(x2) - get_from_fenwick(x1 - 1) << '\n';
        }
        else {
            int x, v;
            cin >> x >> v;

            ll diff = v - arr[x - 1];
            arr[x - 1] = v;
            update_fenwick(x, diff);
        }
    }
}

void solution_2d() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int idx2 = (x - 1) * n + (y - 1);

            int v;
            cin >> v;
            arr[idx2] = v;
            update_fenwick_2d(x, y, v);
        }
    }

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x1, x2, y1, y2;
            cin >> x1 >> x2 >> y1 >> y2;
            x1--; y1--;

            ll ans = get_from_fenwick_2d(x2, y2);
            ans -= get_from_fenwick_2d(x2, y1);
            ans -= get_from_fenwick_2d(x1, y2);
            ans += get_from_fenwick_2d(x1, y1);
            cout << ans << '\n';
        }
        else {
            int x, y, v;
            cin >> x >> y >> v;

            int idx = (x - 1) * n + (y - 1);
            ll diff = v - arr[idx];
            arr[idx] = v;
            update_fenwick_2d(x, y, diff);
        }
    }
}

void solution_3d() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int idx2 = (x - 1) * n + (y - 1);

            for (int z = 1; z <= n; z++) {
                int idx3 = idx2 * n + (z - 1);

                int v;
                cin >> v;
                arr[idx3] = v;
                update_fenwick_3d(x, y, z, v);
            }
        }
    }

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x1, x2, y1, y2, z1, z2;
            cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
            x1--; y1--; z1--;

            ll ans = get_from_fenwick_3d(x2, y2, z2);
            ans -= get_from_fenwick_3d(x2, y2, z1);
            ans -= get_from_fenwick_3d(x2, y1, z2);
            ans -= get_from_fenwick_3d(x1, y2, z2);
            ans += get_from_fenwick_3d(x2, y1, z1);
            ans += get_from_fenwick_3d(x1, y2, z1);
            ans += get_from_fenwick_3d(x1, y1, z2);
            ans -= get_from_fenwick_3d(x1, y1, z1);
            cout << ans << '\n';
        }
        else {
            int x, y, z, v;
            cin >> x >> y >> z >> v;

            int idx = ((x - 1) * n + (y - 1)) * n + (z - 1);
            ll diff = v - arr[idx];
            arr[idx] = v;
            update_fenwick_3d(x, y, z, diff);
        }
    }
}

void solution_4d() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            int idx2 = (x - 1) * n + (y - 1);

            for (int z = 1; z <= n; z++) {
                int idx3 = idx2 * n + (z - 1);

                for (int w = 1; w <= n; w++) {
                    int idx4 = idx3 * n + (w - 1);

                    int v;
                    cin >> v;
                    arr[idx4] = v;
                    update_fenwick_4d(x, y, z, w, v);
                }
            }
        }
    }

    while (q-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int x1, x2, y1, y2, z1, z2, w1, w2;
            cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2 >> w1 >> w2;
            x1--; y1--; z1--; w1--;

            ll ans = get_from_fenwick_4d(x2, y2, z2, w2);
            ans -= get_from_fenwick_4d(x2, y2, z2, w1);
            ans -= get_from_fenwick_4d(x2, y2, z1, w2);
            ans -= get_from_fenwick_4d(x2, y1, z2, w2);
            ans -= get_from_fenwick_4d(x1, y2, z2, w2);
            ans += get_from_fenwick_4d(x2, y2, z1, w1);
            ans += get_from_fenwick_4d(x2, y1, z2, w1);
            ans += get_from_fenwick_4d(x1, y2, z2, w1);
            ans += get_from_fenwick_4d(x2, y1, z1, w2);
            ans += get_from_fenwick_4d(x1, y2, z1, w2);
            ans += get_from_fenwick_4d(x1, y1, z2, w2);
            ans -= get_from_fenwick_4d(x2, y1, z1, w1);
            ans -= get_from_fenwick_4d(x1, y2, z1, w1);
            ans -= get_from_fenwick_4d(x1, y1, z2, w1);
            ans -= get_from_fenwick_4d(x1, y1, z1, w2);
            ans += get_from_fenwick_4d(x1, y1, z1, w1);
            cout << ans << '\n';
        }
        else {
            int x, y, z, w, v;
            cin >> x >> y >> z >> w >> v;

            int idx = (((x - 1) * n + (y - 1)) * n + (z - 1)) * n + (w - 1);
            ll diff = v - arr[idx];
            arr[idx] = v;
            update_fenwick_4d(x, y, z, w, diff);
        }
    }
}

int main() {
    FASTIO;

    cin >> n >> k >> q;

    if (k == 1) solution();
    else if (k == 2) solution_2d();
    else if (k == 3) solution_3d();
    else if (k == 4) solution_4d();

    return 0;
}
