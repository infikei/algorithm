#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n, ans = 0;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            bool start = false, finish = false;
            if ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r)
                start = true;
            if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r)
                finish = true;
            
            if (start != finish) {
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}