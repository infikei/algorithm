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

    int kor_idx;
    cin >> kor_idx;

    int utf_idx = kor_idx + 44031;

    int utf_byte[3] = {
        (utf_idx >> 12) | 0b11100000,
        ((utf_idx >> 6) & 0b00111111) | 0b10000000,
        (utf_idx & 0b00111111) | 0b10000000
    };

    string utf;

    for (int i = 0; i < 3; i++) {
        utf.push_back(utf_byte[i]);
    }

    cout << utf << '\n';

    return 0;
}
