// Solve 2025-02-28

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

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<pii> schedules(n);

    for (int i = 0; i < n; i++) {
        cin >> schedules[i].first >> schedules[i].second;
    }

    sort(schedules.begin(), schedules.end());

    int max_covered = 0;

    for (int i = 0; i < n; i++) {
        int covered = 0;
        int cur = 0;

        for (int j = 0; j < i; j++) {
            cur = max(cur, schedules[j].first);

            if (schedules[j].second > cur) {
                covered += schedules[j].second - cur;
                cur = schedules[j].second;
            }
        }

        for (int j = i + 1; j < n; j++) {
            cur = max(cur, schedules[j].first);

            if (schedules[j].second > cur) {
                covered += schedules[j].second - cur;
                cur = schedules[j].second;
            }
        }

        max_covered = max(max_covered, covered);
    }

    cout << max_covered << '\n';

    return 0;
}
