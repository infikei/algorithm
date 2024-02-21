// Solve 2022-07-12
// Update 2024-02-21

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

string vowels = "aeiou";
int l, c;
char chars[15];
bool chars_checked_vowels[15];
char selected[15];

void dfs(int depth = 0, int begin_idx = 0, int vowel_need = 1, int not_vowel_need = 2) {
    if (depth == l) {
        if (vowel_need <= 0 && not_vowel_need <= 0) {
            for (int i = 0; i < l; i++) {
                cout << selected[i];
            }

            cout << '\n';
        }

        return;
    }

    for (int i = begin_idx; i < c; i++) {
        selected[depth] = chars[i];

        if (chars_checked_vowels[i]) {
            dfs(depth + 1, i + 1, vowel_need - 1, not_vowel_need);
        }
        else {
            dfs(depth + 1, i + 1, vowel_need, not_vowel_need - 1);
        }
    }
}

int main() {
    FASTIO;

    cin >> l >> c;

    for (int i = 0; i < c; i++) {
        cin >> chars[i];
    }

    sort(chars, chars + c);

    for (int i = 0; i < c; i++) {
        for (char v : vowels) {
            if (chars[i] == v) {
                chars_checked_vowels[i] = true;
                break;
            }
        }
    }

    dfs();

    return 0;
}
