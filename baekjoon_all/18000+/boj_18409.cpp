// Solve 2022-11-17
// Update 2023-12-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    char aeiou[5] = { 'a', 'e', 'i', 'o', 'u' };

    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;

    for (char &ch : s) {
        for (char &a : aeiou) {
            if (ch == a) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
