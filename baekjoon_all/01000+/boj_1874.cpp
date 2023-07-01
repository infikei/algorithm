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

    int n;
    cin >> n;

    stack<int> stck;
    string ans = "";
    bool ans_is_vaild = true;
    int stck_in_max = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (x > stck_in_max) {
            stck.push(++stck_in_max);
            ans += "+\n";
        }

        if (x == stck.top()) {
            stck.pop();
            ans += "-\n";
        }
        else {
            ans_is_vaild = false;
            break;
        }
    }

    if (ans_is_vaild) cout << ans << "\n";
    else cout << "NO\n";

    return 0;
}
