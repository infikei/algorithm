// Solve 2025-10-24

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

int get_button_cnt(int cur, int target) {
    int ret = 6; // 숫자 키패드만 누르는 경우

    if (abs(cur - target) % 20 == 0) {
        // UP 또는 DOWN 중 하나의 버튼만 누르면서 양 끝 경계를 안 지나가는 경우
        int cnt = abs(cur - target) / 20;
        ret = min(ret, cnt);
    }

    if (target % 20 == 0) {
        // UP 버튼만 누르면서 양 끝 경계를 지나가는 경우
        int cnt = (146000 - cur) / 20 + 1 + (target - 144000) / 20;
        ret = min(ret, cnt);

        // DOWN 버튼만 누르면서 양 끝 경계를 지나가는 경우
        cnt = (cur - 144000) / 20 + 1 + (146000 - target) / 20;
        ret = min(ret, cnt);
    }

    return ret;
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        double ad, bd, target_d;
        char channel;
        cin >> ad >> bd >> channel >> target_d;
        int a = ad * 1000;
        int b = bd * 1000;
        int target = target_d * 1000;

        int a_cnt = get_button_cnt(a, target) + (channel == 'A' ? 0 : 1);
        int b_cnt = get_button_cnt(b, target) + (channel == 'B' ? 0 : 1);
        cout << min(a_cnt, b_cnt) << '\n';
    }

    return 0;
}
