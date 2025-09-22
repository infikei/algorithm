// Solve 2025-09-21

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

int main() {
    FASTIO;

    int n, p, k;
    cin >> n >> p >> k;
    priority_queue<int, vector<int>, greater<int>> groups[6];

    for (int i = 0; i < n; i++) {
        int t, a;
        cin >> t >> a;
        groups[a].push(t);
    }

    int cur_t = 0;
    int n_group_before_boarding = n;
    ll waiting_time_sum = 0;

    while (n_group_before_boarding > 0) {
        int seat_limit = k; // 놀이기구의 남은 좌석 수

        while (seat_limit > 0) {
            // 도착한 그룹 중에서 가장 빨리 온 그룹을 선택
            int selected_a = -1;

            for (int i = 1; i <= seat_limit; i++) {
                if (!groups[i].empty() && groups[i].top() <= cur_t && (selected_a == -1 || groups[i].top() < groups[selected_a].top())) {
                    selected_a = i;
                }
            }

            // 선택할 수 있는 그룹이 없다면 현재 시각의 탑승 종료
            if (selected_a == -1) {
                break;
            }

            // 선택한 그룹 탑승 처리
            waiting_time_sum += cur_t - groups[selected_a].top();
            groups[selected_a].pop();
            seat_limit -= selected_a;
            n_group_before_boarding--;
        }

        cur_t += p;
    }

    cout << waiting_time_sum << '\n';
    return 0;
}
