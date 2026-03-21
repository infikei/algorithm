// Solve 2026-03-09

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
int cards[100000];
int cnt[260];

bool check(int x) {
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < x; i++) {
        cnt[cards[i]]++;

        if (cnt[cards[i]] >= 5) {
            return true;
        }
    }

    for (int i = x; i < n; i++) {
        cnt[cards[i - x]]--;
        cnt[cards[i]]++;

        if (cnt[cards[i]] >= 5) {
            return true;
        }
    }

    return false;
}

int main() {
    FASTIO;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string card;
        cin >> card;
        cards[i] = (card[0] - '0') * 26 + (card[1] - 'a');
    }

    int low = 4;
    int high = min(n, 137);

    if (!check(high)) {
        cout << -1 << '\n';
        return 0;
    }

    int mn = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << mn << '\n';
    return 0;
}
