// Solve 2025-10-06

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

    int n;
    cin >> n;
    int kbs1 = 0;
    int kbs2 = 0;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        if (s == "KBS1") {
            kbs1 = i;
        }
        else if (s == "KBS2") {
            kbs2 = i;
        }
    }

    // 화살표를 KBS1 위치로 이동
    for (int i = 1; i < kbs1; i++) {
        cout << 1;
    }

    // KBS1 위치를 이동
    for (int i = 1; i < kbs1; i++) {
        cout << 4;
    }

    // 화살표를 KBS2 위치로 이동
    if (kbs2 < kbs1) {
        kbs2++;
    }

    for (int i = 1; i < kbs2; i++) {
        cout << 1;
    }

    // KBS2 위치를 이동
    for (int i = 2; i < kbs2; i++) {
        cout << 4;
    }

    cout << '\n';
    return 0;
}
