#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, ans = 0;
pii building[50];

int ccw(pii a, pii b, pii c) {
    ll ccw_check = (ll)(b.first - a.first) * (ll)(c.second - a.second) - (ll)(b.second - a.second) * (ll)(c.first - a.first);

    if (ccw_check > 0) {
        return 1;
    }
    else if (ccw_check < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        building[i] = make_pair(i, j);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        stack<pii> stck;

        if (i > 0) {
            stck.push(building[i - 1]);

            if (i > 1) {
                for (int j = i - 2; j >= 0; j--) {
                    if (ccw(building[i], stck.top(), building[j]) == -1) {
                        stck.push(building[j]);
                    }
                }
            }
        }

        if (i < N - 1) {
            stck.push(building[i + 1]);

            if (i < N - 2) {
                for (int j = i + 2; j < N; j++) {
                    if (ccw(building[i], stck.top(), building[j]) == 1) {
                        stck.push(building[j]);
                    }
                }
            }
        }

        ans = max(ans, (int)stck.size());
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    cout << ans << '\n';

    return 0;
}