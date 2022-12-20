#include <iostream>
#include <string>
#include <deque>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

string input;
ll ans;
deque<ll> num_dq;
deque<char> op_dq;

ll calc(ll num1, ll num2, char op) {
    if (op == '+') {
        return num1 + num2;
    }
    else if (op == '-') {
        return num1 - num2;
    }
    else if (op == '*') {
        return num1 * num2;
    }
    else {
        return num1 / num2;
    }
}

void input_split() {
    ll tmp = 0;
    int flag = 0;
    if (input[0] == '-') {
        flag = 1;
    }
    for (auto a : input) {
        if (a >= '0' && a <= '9') {
            tmp *= 10;
            tmp += (a - '0');
        }
        else {
            if (flag == 1) {
                flag = 2;
                continue;
            }
            else if (flag == 2) {
                tmp = -tmp;
                flag = 3;
            }
            num_dq.push_back(tmp);
            op_dq.push_back(a);
            tmp = 0;
        }
    }
    if (flag == 2) {
        tmp = -tmp;
    }
    num_dq.push_back(tmp);
}

void solve() {
    while (op_dq.size() > 1) {
        int op_front = (op_dq.front() == '*' || op_dq.front() == '/') ? 2 : 1;
        int op_back = (op_dq.back() == '*' || op_dq.back() == '/') ? 2 : 1;
        if (op_front > op_back) {
            ll num1 = num_dq.front(); num_dq.pop_front();
            ll num2 = num_dq.front(); num_dq.pop_front();
            char op = op_dq.front(); op_dq.pop_front();
            num_dq.push_front(calc(num1, num2, op));
        }
        else if (op_front < op_back) {
            ll num2 = num_dq.back(); num_dq.pop_back();
            ll num1 = num_dq.back(); num_dq.pop_back();
            char op = op_dq.back(); op_dq.pop_back();
            num_dq.push_back(calc(num1, num2, op));
        }
        else {
            ll num1 = num_dq.front(); num_dq.pop_front();
            ll num2 = num_dq.front();
            char op1 = op_dq.front();
            ll res1 = calc(num1, num2, op1);

            ll num4 = num_dq.back(); num_dq.pop_back();
            ll num3 = num_dq.back();
            char op2 = op_dq.back();
            ll res2 = calc(num3, num4, op2);

            if (res1 >= res2) {
                op_dq.pop_front();
                num_dq.pop_front();
                num_dq.push_front(res1);
                num_dq.push_back(num4);
            }
            else if (res1 < res2) {
                op_dq.pop_back();
                num_dq.pop_back();
                num_dq.push_back(res2);
                num_dq.push_front(num1);
            }
        }
    }
    if (op_dq.size() == 1) {
        ll num1 = num_dq.front(); num_dq.pop_front();
        ll num2 = num_dq.front();
        char op = op_dq.front();
        ans = calc(num1, num2, op);
    }
    else {
        ans = num_dq.front();
    }
}

int main() {
    fastio;

    cin >> input;

    input_split();

    solve();

    cout << ans << '\n';

    return 0;
}