#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string big_integer_add(string a, string b) {
    string result;
    int carry = 0;

    while (!a.empty() || !b.empty() || carry) {
        if (!a.empty()) {
            carry += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()) {
            carry += b.back() - '0';
            b.pop_back();
        }
        result.push_back('0' + carry % 10);
        carry = carry / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string A, B;
    cin >> A >> B;

    cout << big_integer_add(A, B) << '\n';

    return 0;
}