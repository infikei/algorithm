#include <iostream>
#include <string>
using namespace std;

string binary_plus(string a, string b) {
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

        result = to_string(sum) + result;
    }

    if (result.find('1') != string::npos) {
        int idx = result.find('1');

        if (idx > 0) {
            int result_sz = result.length();
            result = result.substr(idx, result_sz - idx);
        }
    }
    else {
        result = "0";
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string bin0, bin1;
        cin >> bin0 >> bin1;

        cout << binary_plus(bin0, bin1) << '\n';
    }

    return 0;
}