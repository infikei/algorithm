// Solve 2023-09-05

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string utf;
    cin >> utf;

    int utf_byte[3] = {
        utf[0] & 0b00001111,
        utf[1] & 0b00111111,
        utf[2] & 0b00111111
    };

    int utf_idx = (utf_byte[0] << 12) + (utf_byte[1] << 6) + utf_byte[2];
    int kor_idx = utf_idx - 44031;

    cout << kor_idx << '\n';

    return 0;
}
