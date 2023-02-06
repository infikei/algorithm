#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    map<int, bool> m;
    int A_size, B_size, num, A_and_B_size = 0;

    cin >> A_size >> B_size;

    for (int i = 0; i < A_size; i++) {
        cin >> num;
        m[num] = true;
    }
    for (int i = 0; i < B_size; i++) {
        cin >> num;
        if (m[num]) {
            A_and_B_size++;
        }
    }
    cout << A_size + B_size - A_and_B_size * 2 << '\n';

    return 0;
}