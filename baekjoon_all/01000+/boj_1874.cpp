// Solve 2022-06-05
// Update 2023-03-17

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int main() {
    FASTIO;

    int n;
    cin >> n;

    stack<int> stck;
    bool check = true;
    string ans = "";
    int stck_in_max = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (x > stck_in_max) {
            stck_in_max++;
            stck.push(stck_in_max);
            ans += "+\n";
        }
        if (x == stck.top()) {
            stck.pop();
            ans += "-\n";
        }
        else {
            check = false;
            break;
        }
    }

    if (check) {
        cout << ans << "\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
