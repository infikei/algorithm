// Solve 2025-11-27

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

    vector<int> v;

    for (int i = 3; i <= 1500; i += 2) {
        v.push_back(i * i / 2 + 1);
    }

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        int i = 1;
        int left = 0;

        while (true) {
            if (n < v[left]) {
                while (i <= n) {
                    cout << i << ' ';
                    i++;
                }

                break;
            }

            while (i <= n && i <= v[left] - 3) {
                cout << i << ' ';
                i++;
            }

            cout << i + 1 << ' ' << i << ' ' << i + 2 << ' ';
            i += 3;
            left++;
        }

        cout << '\n';
    }

    return 0;
}
