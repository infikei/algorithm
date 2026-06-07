// Solve 2026-05-24

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

int cnt[26];

void solution() {
    memset(cnt, 0, sizeof(cnt));

    string s;
    cin >> s;
    int n = size(s);

    for (char c : s) {
        cnt[c - 'a']++;
    }

    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > (n + 1) / 2) {
            cout << "No" << '\n';
            return;
        }

        if (cnt[i] > 0) {
            pq.emplace(cnt[i], 'a' + i);
        }
    }

    string ans = "Yes\n";

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if (top.second == ans.back()) {
            auto top2 = pq.top();
            pq.pop();

            ans.push_back(top2.second);
            top2.first--;

            if (top2.first > 0) {
                pq.push(top2);
            }

            pq.push(top);
        }
        else {
            ans.push_back(top.second);
            top.first--;

            if (top.first > 0) {
                pq.push(top);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        solution();
    }

    return 0;
}
