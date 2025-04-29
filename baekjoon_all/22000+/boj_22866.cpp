// Solve 2025-04-29

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

int building[100001];
pii ans[100001];

int choose_nearest_building_num(int cur, int left, int right) {
    if (left == -1) return right;

    int ldist = cur - left;
    int rdist = right - cur;

    if (ldist > rdist) return right;

    return left;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> building[i];
    }

    for (int i = 1; i <= n; i++) {
        ans[i].second = -1;
    }

    stack<int> stck;

    for (int i = 1; i <= n; i++) {
        while (!stck.empty() && building[stck.top()] <= building[i]) {
            stck.pop();
        }

        if (!stck.empty()) {
            ans[i].first += stck.size();
            ans[i].second = stck.top();
        }

        stck.push(i);
    }

    while (!stck.empty()) stck.pop();

    for (int i = n; i >= 1; i--) {
        while (!stck.empty() && building[stck.top()] <= building[i]) {
            stck.pop();
        }

        if (!stck.empty()) {
            ans[i].first += stck.size();
            ans[i].second = choose_nearest_building_num(i, ans[i].second, stck.top());
        }

        stck.push(i);
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i].first == 0) {
            cout << 0 << '\n';
        }
        else {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }

    return 0;
}
