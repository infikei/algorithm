// Solve 2022-12-29
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

char aeiou[5] = { 'a', 'e', 'i', 'o', 'u' };

int main() {
    FASTIO;

    string line, ans;
    getline(cin, line);

    for (int i = 0, ie = SIZE(line); i < ie; i++) {
        ans.push_back(line[i]);

        for (int j = 0; j < 5; j++) {
            if (line[i] == aeiou[j]) {
                i += 2;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
