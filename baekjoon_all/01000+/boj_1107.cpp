// Solve 2023-04-14
// Update 2024-01-27

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    bool btn[10];

    for (int i = 0; i < 10; i++) {
        btn[i] = true;
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        btn[x] = false;
    }

    // Case 1. 100번 채널에서 +와 - 버튼 만으로 이동하는 경우
    int ans = abs(n - 100);

    // Case 2. 숫자버튼으로 입력하여 채널 이동 후 + 버튼으로 이동하는 경우
    // (이 경우 입력한 채널의 번호는 n보다 작음)
    // 채널 번호가 0보다 작은 경우 불가능하므로 while 문을 탈출한다.
    int cur = n;

    while (cur >= 0) {
        string s = to_string(cur);
        bool check = true;

        // 현재 채널 번호를 입력할 수 있는지 여부를 검사
        for (const char ch : s) {
            if (!btn[ch - '0']) {
                check = false;
                break;
            }
        }

        // 현재 채널 번호를 입력할 수 있다면, 정답 업데이트
        if (check) {
            ans = min(ans, SIZE(s) + n - cur);
            break;
        }

        // 현재 채널 번호를 입력할 수 없다면, 채널 번호를 하나 감소시킨다.
        cur--;
    }

    // Case 3. 숫자버튼으로 입력하여 채널 이동 후 - 버튼으로 이동하는 경우
    // (이 경우 입력한 채널의 번호는 n보다 큼)
    // 채널 번호가 1000000보다 큰 경우 불가능하므로 while 문을 탈출한다.
    cur = n;

    while (cur <= 1000000) {
        string s = to_string(cur);
        bool check = true;

        // 현재 채널 번호를 입력할 수 있는지 여부를 검사
        for (const char ch : s) {
            if (!btn[ch - '0']) {
                check = false;
                break;
            }
        }

        // 현재 채널 번호를 입력할 수 있다면, 정답 업데이트
        if (check) {
            ans = min(ans, SIZE(s) + cur - n);
            break;
        }

        // 현재 채널 번호를 입력할 수 없다면, 채널 번호를 하나 증가시킨다.
        cur++;
    }

    cout << ans << '\n';

    return 0;
}
