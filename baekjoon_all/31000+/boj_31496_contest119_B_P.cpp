// Solve 2024-03-02

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
    string s;
    cin >> n >> s;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        string p;
        int k;
        cin >> p >> k;

        stringstream ss(p);
        string w;
        bool flag = false;

        while (getline(ss, w, '_')) {
            if (w == s) {
                flag = true;
                break;
            }
        }

        if (flag) {
            ans += k;
        }
    }

    cout << ans << '\n';

    return 0;
}
