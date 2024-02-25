// Solve 2024-02-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;

struct Item{
    int a, b;

    Item(int a = 0, int b = 0) : a(a), b(b) {}
};

int prev_carrots[5002];
int cur_carrots[5002];

void print() {
    for (int u = 1; u <= 12; u++) {
        cout << prev_carrots[u] << ' ';
    }

    cout << '\n';

    for (int u = 1; u <= 12; u++) {
        cout << cur_carrots[u] << ' ';
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<Item> items(n);

    for (Item &item : items) {
        cin >> item.a >> item.b;
    }

    for (int u = 1; u < 5002; u++) {
        cur_carrots[u] = -1;
    }

    cur_carrots[1] = 0;

    for (int i = 1; i <= k; i++) {
        swap(prev_carrots, cur_carrots);

        for (int u = 1; u <= i * 50 + 1; u++) {
            cur_carrots[u] = -1;
        }

        for (int u = 1; u <= (i - 1) * 50 + 1; u++) {
            if (prev_carrots[u] < 0) continue;

            cur_carrots[u] = max(cur_carrots[u], prev_carrots[u] + u);

            for (Item &item : items) {
                cur_carrots[u + item.b] = max(cur_carrots[u + item.b], prev_carrots[u] - item.a);
            }
        }
    }

    int ans = 0;

    for (int u = 1; u < 5002; u++) {
        ans = max(ans, cur_carrots[u]);
    }

    cout << ans << '\n';

    return 0;
}
