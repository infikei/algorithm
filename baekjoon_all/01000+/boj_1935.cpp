// Solve 2022-08-12
// Update 2024-02-12

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;
    SETPRECISION(2);

    int n;
    string postfix;
    cin >> n >> postfix;

    int nums[26];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    stack<double> stck;

    for (char cur : postfix) {
        if (cur >= 'A' && cur <= 'Z') {
            stck.push(nums[cur - 'A']);
        }
        else if (cur == '+') {
            double tmp = stck.top();
            stck.pop();
            tmp = stck.top() + tmp;
            stck.pop();
            stck.push(tmp);
        }
        else if (cur == '-') {
            double tmp = stck.top();
            stck.pop();
            tmp = stck.top() - tmp;
            stck.pop();
            stck.push(tmp);
        }
        else if (cur == '*') {
            double tmp = stck.top();
            stck.pop();
            tmp = stck.top() * tmp;
            stck.pop();
            stck.push(tmp);
        }
        else {
            double tmp = stck.top();
            stck.pop();
            tmp = stck.top() / tmp;
            stck.pop();
            stck.push(tmp);
        }
    }

    cout << stck.top() << '\n';

    return 0;
}
