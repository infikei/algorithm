// Solve 2025-09-25

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

    int n, m;
    cin >> n >> m;

    int state_change[4] = {63, 42, 21, 9};

    if (n < 6) {
        int bits = 0;

        for (int j = 0; j < n; j++) {
            bits |= (1 << j);
        }

        for (int i = 0; i < 4; i++) {
            state_change[i] &= bits;
        }
    }

    int time_change[4];
    time_change[0] = n;
    time_change[1] = n / 2;
    time_change[2] = (n + 1) / 2;
    time_change[3] = (n + 2) / 3;
    set<int> possible_states;

    for (int i = 0; i < 16; i++) {
        int cur_state = 0;
        int cur_time = 0;

        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                cur_state ^= state_change[j];
                cur_time += time_change[j];
            }
        }

        if (cur_time <= m) {
            possible_states.insert(cur_state);
        }
    }

    cout << size(possible_states) << '\n';
    return 0;
}
