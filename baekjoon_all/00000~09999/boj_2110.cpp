#include <iostream>
#include <algorithm>
using namespace std;

int N, C, houses[200000], ans = 1;

void input() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    sort(houses, houses + N);
}

void solve() {
    int low = 1, high = houses[N - 1] - houses[0], mid;

    while (low <= high) {
        mid = (low + high) / 2;

        int cnt = 1, prev_house = houses[0];
        for (int i = 1; i < N; i++) {
            if (houses[i] - prev_house >= mid) {
                cnt++;
                prev_house = houses[i];
            }
        }

        if (cnt >= C) {
            low = mid + 1;
            if (ans < mid) {
                ans = mid;
            }
        }
        else {
            high = mid - 1;
        }
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