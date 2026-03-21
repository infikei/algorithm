// Solve 2026-03-13

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

string name[50];
double height[50];

int main() {
    FASTIO;

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        double mx_height = 0;

        for (int i = 0; i < n; i++) {
            cin >> name[i] >> height[i];
            mx_height = max(mx_height, height[i]);
        }

        for (int i = 0; i < n; i++) {
            if (height[i] == mx_height) {
                cout << name[i] << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}
