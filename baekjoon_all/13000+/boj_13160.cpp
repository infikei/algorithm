// Solve 2025-05-31

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

    vector<pii> intervals;
    vector<pii> nodes;
    intervals.emplace_back(0, 0);

    for (int i = 1; i <= n; i++) {
        int s, e;
        cin >> s >> e;

        intervals.emplace_back(s, e);
        nodes.emplace_back(s, 0);
        nodes.emplace_back(e, 1);
    }

    sort(nodes.begin(), nodes.end());

    int cur_size = 0;
    int max_size = 0;
    int pos_of_max_size = 0;

    for (pii& node : nodes) {
        if (node.second == 0) {
            cur_size++;

            if (cur_size > max_size) {
                max_size = cur_size;
                pos_of_max_size = node.first;
            }
        }
        else {
            cur_size--;
        }
    }

    cout << max_size << '\n';

    for (int i = 1; i <= n; i++) {
        if (intervals[i].first <= pos_of_max_size && pos_of_max_size <= intervals[i].second) {
            cout << i << ' ';
        }
    }

    cout << '\n';

    return 0;
}
