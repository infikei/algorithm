#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

string unsigned_bigint_add(string a, string b) {
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
        else carry = 0;
        result.push_back('0' + sum);
    }

    reverse(result.begin(), result.end());
    return result;
}

string unsigned_bigint_sub(string a, string b) {
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
        else carry = 0;
        result.push_back('0' + sum);
    }

    // "00123"과 같이 맨 앞에 0이 포함되었을 경우 "123"과 같은 형태로 바꿔주기
    while (result[(int)result.length() - 1] == '0' && (int)result.length() >= 2) {
        result = result.substr(0, (int)result.length() - 1);
    }

    reverse(result.begin(), result.end());
    return result;
}

string unsigned_bigint_mul(string a, string b) {
    if (a == "0" || b == "0") return "0";

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
        for (int i = 0; i < zeros; i++) result2.push_back('0');
        zeros++;
        result = unsigned_bigint_add(result, result2);
    }

    return result;
}

string unsigned_bigint_pow(string a, int b) {
    if (b == 0) return "1";
    if (b == 1) return a;

    // 분할정복을 이용하여 빠르게 계산
    string k = unsigned_bigint_pow(a, b / 2);
    k = unsigned_bigint_mul(k, k);
    if (b % 2 == 1) k = unsigned_bigint_mul(k, a);
    return k;
}

void hanoi_tower(int depth, int s = 1, int mid = 2, int e = 3) {
    if (depth == 1) {
        cout << s << ' ' << e << '\n';
        return;
    }

    hanoi_tower(depth - 1, s, e, mid);
    cout << s << ' ' << e << '\n';
    hanoi_tower(depth - 1, mid, s, e);
}

int main() {
    fastio;

    int n;
    cin >> n;

    string ans = unsigned_bigint_pow("2", n);
    ans = unsigned_bigint_sub(ans, "1");
    cout << ans << '\n';

    if (n <= 20) {
        hanoi_tower(n);
    }

    return 0;
}