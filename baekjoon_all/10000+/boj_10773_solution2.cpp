// Solve 2022-06-05
// Update 2023-07-01

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int k;
    cin >> k;

    stack<int> stck;
    stck.push(0);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;

        if (x == 0) stck.pop();
        else stck.push(stck.top() + x);
    }

    cout << stck.top() << '\n';

    return 0;
}
