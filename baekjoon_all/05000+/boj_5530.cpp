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

bool check(int k) {
    int state[3] = {0};
    int cnt0 = 0;

    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];

        if (c == 'I') {
            if (cnt0 < k) {
                state[0]++;
                cnt0++;
            }
            else if (state[1] >= 1) {
                state[1]--;
                state[2]++;
            }
        }
        else if (c == 'O') {
            if (state[0] >= 1) {
                state[0]--;
                state[1]++;
            }
        }
        else if (c == 'J') {
            if (state[1] >= 1) {
                state[1]--;
                state[2]++;
            }
        }
    }

    return state[2] >= k;
}

int main() {
    FASTIO;

    cin >> n >> s;

    int mx = 0;
    int low = 1;
    int high = 333340;

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
