// Solve 2025-12-02

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

int b[100001];
int w[100001];

int main() {
    FASTIO;

    int n, l;
    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int w_sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        w_sum += w[i];
    }

    int k, p;
    cin >> k >> p;

    int e = l - w_sum;

    if (w[k] > e) {
        int left = 0;
        int right = 0;

        for (int i = 1; i < k; i++) {
            if (w[i] > e) {
                left += w[i];
            }
        }

        for (int i = k + 1; i <= n; i++) {
            if (w[i] > e) {
                right += w[i];
            }
        }

        if (left <= p && p <= l - right - w[k]) {
            cout << "YES" << '\n';
            return 0;
        }

        cout << "NO" << '\n';
    }
    else {
        vector<int> w2;
        int w2_sum = 0;

        for (int i = 1; i <= n; i++) {
            if (w[i] > e) {
                w2.push_back(w[i]);
                w2_sum += w[i];
            }
        }

        int left = 0;
        int right = w2_sum;

        for (int i = 0; i <= size(w2); i++) {
            if (left <= p && p <= l - right - w[k]) {
                cout << "YES" << '\n';
                return 0;
            }

            if (i < size(w2)) {
                left += w2[i];
                right -= w2[i];
            }
        }

        cout << "NO" << '\n';
    }

    return 0;
}
