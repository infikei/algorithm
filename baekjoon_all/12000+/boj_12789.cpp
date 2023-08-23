// Solve 2023-08-22

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    stack<int> stck, stck2;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        stck2.push(x);
    }

    while (!stck2.empty()) {
        stck.push(stck2.top());
        stck2.pop();
    }

    int cur = 0;

    while (cur < n) {
        cur++;

        if (!stck2.empty() && stck2.top() == cur) {
            stck2.pop();
        }
        else {
            while (!stck.empty() && stck.top() != cur) {
                stck2.push(stck.top());
                stck.pop();
            }

            if (stck.empty()) break;
            else stck.pop();
        }
    }

    if (cur == n) cout << "Nice\n";
    else cout << "Sad\n";

    return 0;
}
