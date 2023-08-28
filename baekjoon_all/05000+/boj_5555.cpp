// Solve 2023-04-08
// Update 2023-08-28

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

    int n;
    cin >> n;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string ring;
        cin >> ring;

        ring += ring;

        for (int j = 0; j < 10; j++) {
            if (ring.substr(j, SIZE(word)) == word) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
