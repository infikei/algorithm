#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string a, b;
    cin >> a >> b;

    string ans;
    int sum = 0, carry = 0;
    while (!a.empty() || !b.empty() || carry) {
        sum = carry;
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        if (sum >= 2) {
            sum -= 2;
            carry = 1;
        }
        else carry = 0;
        ans = to_string(sum) + ans;
    }

    if (ans.find('1') == string::npos) ans = "0";
    else {
        int idx = ans.find('1');
        if (idx > 0) {
            ans = ans.substr(idx);
        }
    }

    cout << ans << '\n';

    return 0;
}