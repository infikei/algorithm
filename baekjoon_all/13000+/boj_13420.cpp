#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

ll calc(ll num1, ll num2, char op) {
    if (op == '+') return num1 + num2;
    else if (op == '-') return num1 - num2;
    else if (op == '*') return num1 * num2;
    else return num1 / num2;
}

int main() {
    fastio;

    int T;
    cin >> T;

    ll num1, num2, num3;
    char op1, op2;
    for (int t = 0; t < T; t++) {
        cin >> num1 >> op1 >> num2 >> op2 >> num3;

        bool check = false;
        if (op1 == '=') {
            if (num1 == calc(num2, num3, op2)) check = true;
        }
        else {
            if (num3 == calc(num1, num2, op1)) check = true;
        }

        if (check) cout << "correct\n";
        else cout << "wrong answer\n";
    }

    return 0;
}