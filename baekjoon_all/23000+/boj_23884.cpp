// Solve 2025-09-23

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

int a[500001];

void print_a(int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }

    cout << '\n';
}

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;
    set<pii> a_idx;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a_idx.emplace(a[i], i);
    }

    int cnt = 0;

    for (int i = n; i >= 2; i--) {
        int pos = a_idx.rbegin()->second; // 배열의 1 ~ i번째 수 중에서 가장 큰 값의 위치

        if (pos == i) {
            a_idx.erase({a[i], i});
            continue;
        }

        a_idx.erase({a[pos], pos});
        a_idx.erase({a[i], i});
        swap(a[pos], a[i]);
        a_idx.insert({a[pos], pos});

        if (++cnt == k) {
            print_a(n);
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
