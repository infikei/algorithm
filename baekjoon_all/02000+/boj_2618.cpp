// Solve 2023-02-10

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)1e9
#define LLINF (ll)4e18
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;

int n, w;
pii events[1001];
int total_dist[1001][1001];

int calc_dist(pii pt1, pii pt2) {
    return abs(pt1.first - pt2.first) + abs(pt1.second - pt2.second);
}

int calc_total_dist(int event1, int event2) {
    if (event1 == w || event2 == w) return 0;
    if (total_dist[event1][event2] != -1) return total_dist[event1][event2];

    int next_event = max(event1, event2) + 1;

    int res1 = calc_total_dist(next_event, event2);
    if (event1 == 0) res1 += calc_dist({ 1, 1 }, events[next_event]);
    else res1 += calc_dist(events[event1], events[next_event]);

    int res2 = calc_total_dist(event1, next_event);
    if (event2 == 0) res2 += calc_dist({ n, n }, events[next_event]);
    else res2 += calc_dist(events[event2], events[next_event]);

    total_dist[event1][event2] = min(res1, res2);
    return total_dist[event1][event2];
}

void find_path(int event1, int event2) {
    if (event1 == w || event2 == w) return;

    int next_event = max(event1, event2) + 1;

    int res1 = total_dist[next_event][event2];
    if (event1 == 0) res1 += calc_dist({ 1, 1 }, events[next_event]);
    else res1 += calc_dist(events[event1], events[next_event]);

    int res2 = total_dist[event1][next_event];
    if (event2 == 0) res2 += calc_dist({ n, n }, events[next_event]);
    else res2 += calc_dist(events[event2], events[next_event]);

    if (res1 < res2) {
        cout << 1 << '\n';
        find_path(next_event, event2);
    }
    else {
        cout << 2 << '\n';
        find_path(event1, next_event);
    }
}

int main() {
    FASTIO;

    cin >> n >> w;
    for (int i = 1; i <= w; i++) {
        int x, y;
        cin >> x >> y;
        events[i] = { x, y };
    }

    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= w; j++) {
            total_dist[i][j] = -1;
        }
    }

    cout << calc_total_dist(0, 0) << '\n';

    find_path(0, 0);

    return 0;
}