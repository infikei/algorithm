// Solve 2023-03-20
// Update 2023-08-27

// 백준 같은 문제 : 1251번 = 2993번

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string s;
    cin >> s;

    string ans = s;
    reverse(ans.begin() + 2, ans.end());

    for (int i = 1, ie = SIZE(s); i < ie; i++) {
        string s2 = s;
        reverse(s2.begin(), s2.begin() + i);

        for (int j = i + 1, je = SIZE(s); j < je; j++) {
            string s3 = s2;
            reverse(s3.begin() + i, s3.begin() + j);
            reverse(s3.begin() + j, s3.end());

            ans = min(ans, s3);
        }
    }

    cout << ans << '\n';

    return 0;
}
