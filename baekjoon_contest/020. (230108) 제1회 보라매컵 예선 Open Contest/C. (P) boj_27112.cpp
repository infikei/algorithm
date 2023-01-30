#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;

int n, ans;
priority_queue<pii, vector<pii>, greater<pii> > pq_mintop;

int calc_work0(int d) {
    int res = (d - 1) / 7 * 5;
    res += min(5, (d - 1) % 7 + 1);
    return res;
}

int main() {
    fastio;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, t;
        cin >> d >> t;
        pq_mintop.push(make_pair(d, t));
    }

    int day = 0, work0 = 0, work1 = 0, tmp_work0 = 0;
    bool check = true;
    while (!pq_mintop.empty()) {
        pii pq_top = pq_mintop.top();
        pq_mintop.pop();

        work0 -= tmp_work0;
        tmp_work0 = calc_work0(pq_top.first);
        work0 += tmp_work0;
        work1 += pq_top.first - day;
        day = pq_top.first;

        work0 -= pq_top.second;
        if (work0 < 0) {
            work1 += work0;
            ans -= work0;
            work0 = 0;
            if (work1 < 0) {
                check = false;
                break;
            }
        }
    }

    if (check) cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}