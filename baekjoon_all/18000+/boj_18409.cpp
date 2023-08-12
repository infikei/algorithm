// Solve 2022-11-17
// Update 2023-08-12

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

    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;

    for (const char ch : s) {
        for (const char a : aeiou) {
            if (ch == a) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
