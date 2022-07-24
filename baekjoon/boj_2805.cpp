#include <iostream>
using namespace std;

int trees_height[1000000];
int max_height;
int N, M, ans;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> M;
    max_height = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees_height[i];
        if (trees_height[i] > max_height) {
            max_height = trees_height[i];
        }
    }

    ans = 0;
    long long low = 0, high = max_height, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        long long now = 0;
        // mid 최댓값 = 5*10^8
        // -> now 최댓값 = mid 최댓값 * N 최댓값 = 5*10^8 * 10*6 = 5*10^14 이므로
        // now 역시 long long 자료형으로 선언해야 한다.
        for (int i = 0; i < N; i++) {
            if (trees_height[i] > mid) {
                now += trees_height[i] - mid;
            }
        }

        if (now >= M) {
            low = mid + 1;
            if (mid > ans) {
                ans = mid;
            }
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}