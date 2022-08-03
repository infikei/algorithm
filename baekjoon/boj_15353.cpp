// boj_10757.cpp와 동일한 풀이

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool big_number_smaller(string a, string b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    }
    else {
        return a.length() < b.length();
    }
}

string big_number_add(string a, string b) {
    if (big_number_smaller(a, b)) {
        return big_number_add(b, a);
    }

    string result = "";
    int sum = 0, carry = 0;
    int a_length = a.length();
    int b_length = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < b_length; i++) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result += (sum + '0');
    }
    for (int i = b_length; i < a_length; i++) {
        sum = (a[i] - '0') + carry;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result += (sum + '0');
    }
    if (carry == 1) {
        result += '1';
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

    cout << big_number_add(A, B) << '\n';

    return 0;
}