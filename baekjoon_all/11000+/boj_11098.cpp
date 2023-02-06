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
        int P;
        cin >> P;

        int price, max_price = 0;
        string name, max_name;

        for (int p = 0; p < P; p++) {
            cin >> price >> name;

            if (price > max_price) {
                max_price = price;
                max_name = name;
            }
        }

        cout << max_name << '\n';
    }

    return 0;
}