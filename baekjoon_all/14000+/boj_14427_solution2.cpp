// Solve 2023-06-12
// Update 2025-07-26

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

int arr[100001];

int main() {
    FASTIO;

    int n;
    cin >> n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        arr[i] = v;
        pq.emplace(v, i);
    }

    int m;
    cin >> m;

    while (m-- > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int i, v;
            cin >> i >> v;
            arr[i] = v;
            pq.emplace(v, i);
        }
        else {
            while (pq.top().first != arr[pq.top().second]) {
                pq.pop();
            }

            cout << pq.top().second << '\n';
        }
    }

    return 0;
}
