// Solve 2025-03-29

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

    int n, m, k, l;
    cin >> n >> m >> k >> l;

    // 거대 질량 천체와 시공간 왜곡은 신경쓰지 않아도 된다.
    // 지나는 칸의 이동 시간을 모두 더하면 결국 출발 지점과 도착 지점의 시공간 왜곡 차이가 되기 때문이다.
    // 즉, 출발 지점과 도착 지점이 같으면 어떤 경로로 이동하든 이동 시간은 이미 결정되어 있다.
    for (int i = 0; i < k; i++) {
        int rk, ck;
        cin >> rk >> ck;
    }

    int min_moved_cnt = n + m - 2; // 도착 지점에 도착하기 위해 필요한 최소 이동 횟수

    // 정확히 L번의 이동 횟수로 도착 지점에 도착할 수 없는 경우
    if (l < min_moved_cnt || min_moved_cnt % 2 != l % 2) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = min_moved_cnt; i < l; i += 2) {
        cout << "RL";
    }

    for (int i = 1; i < n; i++) {
        cout << 'D';
    }

    for (int i = 1; i < m; i++) {
        cout << 'R';
    }

    cout << '\n';

    return 0;
}
