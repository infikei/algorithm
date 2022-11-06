#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string unsigned_big_binary_int_add(string a, string b) {
    string result;
    int sum = 0, carry = 0;

    while (!a.empty() || !b.empty() || carry) {
        sum = carry;
        if (!a.empty()) {
            sum += (a.back() - '0');
            a.pop_back();
        }
        if (!b.empty()) {
            sum += (b.back() - '0');
            b.pop_back();
        }
        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result.push_back('0' + sum);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string N;
    cin >> N;

    string N16;
    N16 = N;
    for (int i = 0; i < 4; i++) {
        N16.push_back('0');
    }

    cout << unsigned_big_binary_int_add(N16, N) << '\n';

    return 0;
}