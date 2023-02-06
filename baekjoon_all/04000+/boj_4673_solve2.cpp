#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    bool check[10001] = {false};
    int sum;
    string s;

    for (int i = 1; i < 10001; i++) {
        sum = i;
        s = to_string(i);

        for (int j = 0; j < s.size(); j++) {
            sum += (s[j] - '0');
        }

        if (sum < 10001) {
            check[sum] = true;
        }
    }

    for (int i = 1; i < 10001; i++) {
        if (!check[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}