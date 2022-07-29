#include <iostream>
#include <algorithm>
using namespace std;

int score[5];
int T;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> T;

    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 5; i++) {
            cin >> score[i];
        }

        sort(score, score + 5);

        if (score[3] - score[1] >= 4) {
            cout << "KIN" << '\n';
        }
        else {
            int ans = score[1] + score[2] + score[3];
            cout << ans << '\n';
        }
    }

    return 0;
}