#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    cout << "int a;\n";

    for (int n = 1; n <= N; n++) {
        cout << "int ";
        for (int i = 1; i <= n; i++) {
            cout << '*';
        }

        if (n > 2) {
            cout << "ptr" << n << " = &ptr" << n - 1 << ";\n";
        }
        else if (n == 2) {
            cout << "ptr" << n << " = &ptr;\n";
        }
        else {
            cout << "ptr" << " = &a;\n";
        }
    }

    return 0;
}