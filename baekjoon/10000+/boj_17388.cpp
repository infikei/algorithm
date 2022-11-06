#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int score[3], score_sum = 0;

    for (int i = 0; i < 3; i++) {
        cin >> score[i];
        score_sum += score[i];
    }

    if (score_sum >= 100) {
        cout << "OK";
    } else {
        int min_score = score[0];
        int min_idx = 0;
        for (int i = 1; i < 3; i++) {
            if (score[i] < min_score) {
                min_score = score[i];
                min_idx = i;
            }
        }

        if (min_idx == 0) {
            cout << "Soongsil";
        } else if (min_idx == 1) {
            cout << "Korea";
        } else {
            cout << "Hanyang";
        }
    }
    cout << '\n';

    return 0;
}