#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N;

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

string Fibonacci_big(int n) {
    if (n == 0) {
        return "0";
    }

    string F_val[3] = {"0", "0", "1"};
    for (int i = 2; i <= N; i++) {
        F_val[0] = F_val[1];
        F_val[1] = F_val[2];
        F_val[2] = unsigned_big_int_add(F_val[0], F_val[1]);
    }
    return F_val[2];
}

int main() {
    fastio;

    cin >> N;

    cout << Fibonacci_big(N) << '\n';

    return 0;
}