#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<bool, string> bigint;

bigint string_to_big_int(string s) {
    if (s == "-0") {
        s = "0";
    }
    if (s[0] == '-') {
        return make_pair(false, s.substr(1));
    }
    else {
        return make_pair(true, s);
    }
}

string big_int_to_string(bigint b) {
    if (b.first) {
        return b.second;
    }
    else {
        return "-" + b.second;
    }
}

bool unsigned_big_int_lt(const string& a, const string& b) {
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

string unsigned_big_int_add(string a, string b) {
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
        if (sum >= 10) {
            sum -= 10;
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

string unsigned_big_int_sub(string a, string b) {
    if (a == b) {
        return "0";
    }
    if (unsigned_big_int_lt(a, b)) {
        return unsigned_big_int_sub(b, a);
    }

    string result;
    int sum = 0, carry = 0;

    while (!a.empty() || !b.empty() || carry) {
        sum = carry;
        if (!a.empty()) {
            sum += (a.back() - '0');
            a.pop_back();
        }
        if (!b.empty()) {
            sum -= (b.back() - '0');
            b.pop_back();
        }
        if (sum < 0) {
            sum += 10;
            carry = -1;
        }
        else {
            carry = 0;
        }
        result.push_back('0' + sum);
    }

    // "00123"과 같이 맨 앞에 0이 포함되었을 경우 "123"과 같은 형태로 바꿔주기
    while (result[result.length() - 1] == '0' && result.length() >= 2) {
        result = result.substr(0, result.length() - 1);
    }

    reverse(result.begin(), result.end());
    return result;
}

string unsigned_big_int_mult(string a, string b) {
    if (a == "0" || b == "0") {
        return "0";
    }

    string result, result2, a_copy, b_copy;

    int sum = 0, carry = 0, now = 0, zeros = 0;

    b_copy = b;
    result = "";
    while (!b_copy.empty()) {
        now = (b_copy.back() - '0');
        b_copy.pop_back();

        a_copy = a;
        result2 = "";
        while (!a_copy.empty() || carry) {
            sum = 0;
            if (!a_copy.empty()) {
                sum += (a_copy.back() - '0') * now;
                a_copy.pop_back();
            }
            sum += carry;
            carry = 0;
            while (sum >= 10) {
                sum -= 10;
                carry++;
            }
            result2.push_back('0' + sum);
        }

        reverse(result2.begin(), result2.end());
        for (int i = 0; i < zeros; i++) {
            result2.push_back('0');
        }
        zeros++;
        result = unsigned_big_int_add(result, result2);
    }

    return result;
}

bool big_int_lt(const bigint& a, const bigint& b) {
    if (a.first) {
        if (b.first) {
            return unsigned_big_int_lt(a.second, b.second);
        }
        else {
            return false;
        }
    }
    else {
        if (b.first) {
            return true;
        }
        else {
            return unsigned_big_int_lt(b.second, a.second);
        }
    }
}

bigint big_int_add(bigint a, bigint b) {
    if (a.first) {
        if (b.first) {
            return make_pair(true, unsigned_big_int_add(a.second, b.second));
        }
        else {
            return make_pair(!unsigned_big_int_lt(a.second, b.second), unsigned_big_int_sub(a.second, b.second));
        }
    }
    else {
        if (b.first) {
            return make_pair(!unsigned_big_int_lt(b.second, a.second), unsigned_big_int_sub(a.second, b.second));
        }
        else {
            return make_pair(false, unsigned_big_int_add(a.second, b.second));
        }
    }
}

bigint big_int_sub(bigint a, bigint b) {
    if (b.first && b.second == "0") {
        return a;
    }
    b.first = !b.first;
    return big_int_add(a, b);
}

bigint big_int_mult(bigint a, bigint b) {
    if (a.second == "0" || b.second == "0") {
        return make_pair(true, "0");
    }
    if (a.first == b.first) {
        return make_pair(true, unsigned_big_int_mult(a.second, b.second));
    }
    else {
        return make_pair(false, unsigned_big_int_mult(a.second, b.second));
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    string A, B;
    cin >> A >> B;

    bigint A_bigint = string_to_big_int(A);
    bigint B_bigint = string_to_big_int(B);

    cout << big_int_to_string(big_int_add(A_bigint, B_bigint)) << '\n';
    cout << big_int_to_string(big_int_sub(A_bigint, B_bigint)) << '\n';
    cout << big_int_to_string(big_int_mult(A_bigint, B_bigint)) << '\n';

    return 0;
}