#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int ans = 0, temp = 0;
    string input;

    for (int i = 0; i < 3; i++) {
        cin >> input;

        if (input == "black") {
            temp = 0;
        }
        else if (input == "brown") {
            temp = 1;
        }
        else if (input == "red") {
            temp = 2;
        }
        else if (input == "orange") {
            temp = 3;
        }
        else if (input == "yellow") {
            temp = 4;
        }
        else if (input == "green") {
            temp = 5;
        }
        else if (input == "blue") {
            temp = 6;
        }
        else if (input == "violet") {
            temp = 7;
        }
        else if (input == "grey") {
            temp = 8;
        }
        else if (input == "white") {
            temp = 9;
        }

        if (i == 0) {
            ans += temp * 10;
        }
        else if (i == 1) {
            ans += temp;
        }
        else {
            if (ans == 0) {
                cout << 0;
            }
            else {
                cout << ans;
                for (int j = 0; j < temp; j++) {
                    cout << 0;
                }
            }
        }
    }

    return 0;
}