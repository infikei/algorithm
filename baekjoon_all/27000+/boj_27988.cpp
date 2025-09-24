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

struct Ribbon{
    int idx;
    int from;
    int to;

    Ribbon(int idx, int from, int to) : idx(idx), from(from), to(to) {
    }

    bool operator<(const Ribbon& rhs) const {
        return from < rhs.from;
    }
};

int x[1000000];
int l[1000000];
int c[1000000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        c[i] = (ch == 'R' ? 0 : ch == 'Y' ? 1 : 2);
    }

    vector<Ribbon> ribbons[3];

    for (int i = 0; i < n; i++) {
        ribbons[c[i]].emplace_back(i, x[i] - l[i], x[i] + l[i]);
    }

    for (int i = 0; i < 3; i++) {
        sort(ribbons[i].begin(), ribbons[i].end());
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            vector<Ribbon>& ri = ribbons[i];
            vector<Ribbon>& rj = ribbons[j];
            int ii = 0;
            int jj = 0;

            while (ii < size(ri) && jj < size(rj)) {
                if (ri[ii].to < rj[jj].from) {
                    ii++;
                }
                else if (rj[jj].to < ri[ii].from) {
                    jj++;
                }
                else {
                    cout << "YES" << '\n';
                    cout << ri[ii].idx + 1 << ' ' << rj[jj].idx + 1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}
