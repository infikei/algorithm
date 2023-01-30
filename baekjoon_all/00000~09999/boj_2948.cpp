#include <iostream>
using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int M, D;
    cin >> D >> M;

    for (int m = 0; m < M - 1; m++) {
        D += days[m];
    }

    if (D % 7 == 0) {
        cout << "Wednesday";
    }
    else if (D % 7 == 1) {
        cout << "Thursday";
    }
    else if (D % 7 == 2) {
        cout << "Friday";
    }
    else if (D % 7 == 3) {
        cout << "Saturday";
    }
    else if (D % 7 == 4) {
        cout << "Sunday";
    }
    else if (D % 7 == 5) {
        cout << "Monday";
    }
    else {
        cout << "Tuesday";
    }
    cout << '\n';

    return 0;
}