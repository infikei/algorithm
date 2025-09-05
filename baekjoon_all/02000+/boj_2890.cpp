// Solve 2025-09-03

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

    int r, c;
    cin >> r >> c;

    int pos[10];

    for (int x = 0; x < r; x++) {
        string row;
        cin >> row;

        for (int y = 0; y < c; y++) {
            if (isdigit(row[y])) {
                pos[row[y] - '0'] = y;
            }
        }
    }

    vector<pii> vec;

    for (int i = 1; i <= 9; i++) {
        vec.emplace_back(-pos[i], i);
    }

    sort(vec.begin(), vec.end());
    int rank[10];
    rank[vec[0].second] = 1;

    for (int i = 1; i < 9; i++) {
        if (vec[i - 1].first == vec[i].first) {
            rank[vec[i].second] = rank[vec[i - 1].second];
        }
        else {
            rank[vec[i].second] = rank[vec[i - 1].second] + 1;
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << rank[i] << '\n';
    }

    return 0;
}
