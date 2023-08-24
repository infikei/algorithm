// Solve 2022-06-07
// Update 2023-08-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string word;
    cin >> word;

    int ans = SIZE(word);

    for (int i = 0, ie = SIZE(word); i < ie; i++) {
        if (word[i] == '=') {
            if (i >= 2) {
                if (word[i - 2] == 'd' && word[i - 1] == 'z') {
                    ans -= 2;
                }
                else {
                    ans--;
                }
            }
            else {
                ans--;
            }
        }
        else if (word[i] == '-') {
            ans--;
        }
        else if (word[i] == 'j' && i >= 1) {
            if (word[i - 1] == 'l' || word[i - 1] == 'n') {
                ans--;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
