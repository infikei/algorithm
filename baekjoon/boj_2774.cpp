#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string X;
        cin >> X;

        bool check[10];
        for (int i = 0; i < 10; i++) {
            check[i] = false;
        }

        for (auto x : X) {
            check[x - '0'] = true;
        }

        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (check[i]) {
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}