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

    string kor2[3];

    for (int i = 0; i < 3; i++) {
        cin >> kor2[i];
    }

    vector<vector<string> > kor2_vec = {
        { "ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ", "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" },
        { "ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ" },
        { "", "ㄱ", "ㄲ", "ㄳ", "ㄴ", "ㄵ", "ㄶ", "ㄷ", "ㄹ", "ㄺ", "ㄻ", "ㄼ", "ㄽ", "ㄾ", "ㄿ", "ㅀ", "ㅁ", "ㅂ", "ㅄ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" }
    };

    int kor2_idx[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0, je = SIZE(kor2_vec[i]); j < je; j++) {
            if (kor2_vec[i][j] == kor2[i]) {
                kor2_idx[i] = j;
                break;
            }
        }
    }

    int kor_idx = (kor2_idx[0] * 21 + kor2_idx[1]) * 28 + kor2_idx[2];
    int utf_idx = kor_idx + 44032;

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
