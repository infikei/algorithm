// Solve 2025-12-08

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

int b[500000];
int t[500000];

void binary_search(int v, int l, int r) {
    if (l > r) return;

    int mid = (l + r) / 2;
    b[mid] = v;
    binary_search(v + 1, l, mid - 1);
    binary_search(v + 1, mid + 1, r);
}

void ternary_search(int v, int l, int r) {
    if (l > r) return;

    int l_third = l + (r - l) / 3;
    int r_third = r - (r - l) / 3;
    t[l_third] = v;
    if (l_third != r_third) t[r_third] = v + 1;
    ternary_search(v + 2, l, l_third - 1);
    ternary_search(v + 2, l_third + 1, r_third - 1);
    ternary_search(v + 2, r_third + 1, r);
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    binary_search(0, 0, n - 1);
    ternary_search(0, 0, n - 1);

    int lt = 0, eq = 0, gt = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] < t[i]) lt++;
        else if (b[i] > t[i]) gt++;
        else eq++;
    }

    cout << lt << '\n';
    cout << eq << '\n';
    cout << gt << '\n';
    return 0;
}
