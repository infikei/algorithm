#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int cnt1 = 0, cnt2 = 0;

        for (int n = 0; n < N; n++) {
            char ch1, ch2;
            cin >> ch1 >> ch2;

            if (ch1 == ch2) {
                continue;
            }

            if (ch1 == 'R') {
                if (ch2 == 'S') {
                    cnt1++;
                }
                else {
                    cnt2++;
                }
            }
            else if (ch1 == 'P') {
                if (ch2 == 'R') {
                    cnt1++;
                }
                else {
                    cnt2++;
                }
            }
            else {
                if (ch2 == 'P') {
                    cnt1++;
                }
                else {
                    cnt2++;
                }
            }
        }

        if (cnt1 > cnt2) {
            cout << "Player 1\n";
        }
        else if (cnt1 < cnt2) {
            cout << "Player 2\n";
        }
        else {
            cout << "TIE\n";
        }
    }

    return 0;
}