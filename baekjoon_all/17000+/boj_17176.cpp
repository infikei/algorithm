// Solve 2025-11-20

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

int cnt[53];
int cnt2[53];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        cnt[v]++;
    }

    cin.ignore();
    string s;
    getline(cin, s);

    for (char c : s) {
        if (c == ' ') cnt2[0]++;
        else if (c <= 'Z') cnt2[c - 'A' + 1]++;
        else cnt2[c - 'a' + 27]++;
    }

    for (int i = 0; i < 53; i++) {
        if (cnt[i] != cnt2[i]) {
            cout << "n" << '\n';
            return 0;
        }
    }

    cout << "y" << '\n';
    return 0;
}
