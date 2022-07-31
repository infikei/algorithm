#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string grade;
    double score;

    cin >> grade;

    if (grade == "F") {
        score = 0;
    }
    else {
        score = 4 - (grade[0] - 'A');

        if (grade[1] == '+') {
            score += 0.3;
        }
        else if (grade[1] == '-') {
            score -= 0.3;
        }
    }

    cout << fixed;
    cout.precision(1);
    cout << score << '\n';

    return 0;
}