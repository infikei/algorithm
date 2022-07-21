#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int students[31] = {0};
    int student_id;

    for (int i = 0; i < 28; i++) {
        cin >> student_id;
        students[student_id] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        if (students[i] == 0) {
            cout << i << '\n';
        }
    }

    return 0;
}