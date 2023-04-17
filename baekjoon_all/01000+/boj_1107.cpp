// Solve 2023-04-14

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

bool btn[10];

int main() {
    FASTIO;

    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i = 0; i < 10; i++) {
        btn[i] = true;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        btn[x] = false;
    }

    // 100번 채널에서 +와 - 버튼 만으로 이동하는 경우
    int ans = abs(n - 100);

    // 숫자버튼으로 입력하여 채널 이동 후 + 버튼으로 이동하는 경우
    // (이 경우 입력한 채널의 번호는 n보다 작음)
    int cur = n;
    while (true) {
        string s = to_string(cur);
        bool check = true;
        for (auto ch : s) {
            if (!btn[ch - '0']) {
                check = false;
                break;
            }
        }
        if (!check) {
            cur--;
            if (cur < 0) {
                break;
            }
            else {
                continue;
            }
        }

        ans = min(ans, SIZE(s) + n - cur);
        break;
    }

    // 숫자버튼으로 입력하여 채널 이동 후 - 버튼으로 이동하는 경우
    // (이 경우 입력한 채널의 번호는 n보다 큼)
    cur = n;
    while (true) {
        string s = to_string(cur);
        bool check = true;
        for (auto ch : s) {
            if (!btn[ch - '0']) {
                check = false;
                break;
            }
        }
        if (!check) {
            cur++;
            if (cur > 1000000) {
                break;
            }
            else {
                continue;
            }
        }

        ans = min(ans, SIZE(s) + cur - n);
        break;
    }

    cout << ans << '\n';

    return 0;
}
