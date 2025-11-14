// Solve 2025-11-11

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

int n;
string s;
int cnt[128];

bool check(int k) {
    int state[6] = {0};
    int g = 0;

    for (char c : s) {
        if (c == 's') {
            state[0]++;
        }
        else if (c == 'o') {
            if (state[0] >= 1) {
                state[0]--;
                state[1]++;
            }
        }
        else if (c == 'a') {
            if (state[2] >= 1) {
                state[2]--;
                state[3]++;
            }
        }
        else if (c == 'n') {
            if (state[3] >= 1) {
                state[3]--;
                state[4]++;
            }
        }
        else if (c == 'g') {
            if (g < k && state[1] >= 1) {
                state[1]--;
                state[2]++;
                g++;
            }
            else if (state[4] >= 1) {
                state[4]--;
                state[5]++;
            }
        }
    }

    return state[5] >= k;
}

int main() {
    FASTIO;

    cin >> n >> s;

    for (char c : s) {
        cnt[c]++;
    }

    int mx = 0;
    int low = 1;
    int high = min({cnt['s'], cnt['o'], cnt['a'], cnt['n'], cnt['g'] / 2});

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            mx = max(mx, mid);
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << mx << '\n';
    return 0;
}
