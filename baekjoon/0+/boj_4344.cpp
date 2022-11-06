#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int c, n, sum;
    int score[1000] = {0};
    float average;
    cin >> c;

    cout << fixed;
    cout.precision(3);

    for (int i = 0; i < c; i++) {
        cin >> n;
        sum = 0;

        for (int j = 0; j < n; j++) {
            cin >> score[j];
            sum += score[j];
        }

        average = (sum * 1.0) / n;
        sum = 0;

        for (int j = 0; j < n; j++) {
            if (score[j] > average) {
                sum++;
            }
        }

        cout << ((sum * 100.0) / n) << "%\n";
    }

    return 0;
}