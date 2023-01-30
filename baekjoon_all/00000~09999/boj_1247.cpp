#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;
using bigint = pair<bool, string>;

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

bool unsigned_big_int_lt(const string& a, const string& b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < (int)a.length(); i++) {
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
    while (result[(int)result.length() - 1] == '0' && (int)result.length() >= 2) {
        result = result.substr(0, (int)result.length() - 1);
    }

    reverse(result.begin(), result.end());
    return result;
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

int main() {
    fastio;

    int T = 3;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        string S;
        cin >> S;
        bigint ans = string_to_big_int(S);

        for (int n = 1; n < N; n++) {
            cin >> S;
            ans = big_int_add(ans, string_to_big_int(S));
        }

        if (ans.second == "0") {
            cout << "0\n";
            
        }
        else if (ans.first) {
            cout << "+\n";
        }
        else {
            cout << "-\n";
        }
    }

    return 0;
}