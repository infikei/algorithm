// Solve 2026-09-04

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

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    vector<int> comb;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        comb.push_back(x);
    }

    vector<bool> visited(n + 1);
    bool flag = false;

    for (int i = k - 1; i >= 0; i--) {
        if (comb[i] + 1 <= n && !visited[comb[i] + 1]) {
            comb[i] += 1;

            for (int j = i + 1; j < k; j++) {
                comb[j] = comb[j - 1] + 1;
            }

            flag = true;
            break;
        }

        visited[comb[i]] = true;
    }

    if (!flag) {
        cout << "NONE" << '\n';
        return 0;
    }

    for (int i = 0; i < k; i++) {
        cout << comb[i] << ' ';
    }

    cout << '\n';
    return 0;
}
