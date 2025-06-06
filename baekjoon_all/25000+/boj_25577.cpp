// Solve 2025-06-06

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

int arr[100000];
int sorted_arr[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }

    sort(sorted_arr, sorted_arr + n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[sorted_arr[i]] = arr[i];
    }

    set<int> visited;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int from = sorted_arr[i];

        if (visited.find(from) != visited.end()) {
            continue;
        }

        int cur = mp[from];
        visited.insert(cur);
        int cnt = 0;

        while (cur != from) {
            cur = mp[cur];
            visited.insert(cur);
            cnt++;
        }

        ans += cnt;
    }

    cout << ans << '\n';

    return 0;
}
