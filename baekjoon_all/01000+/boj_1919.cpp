#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

string word[2];
int alphabet_cnt_in_word[2][26], ans;

int main() {
    fastio;

    for (int i = 0; i < 2; i++) {
        cin >> word[i];
        for (auto a : word[i]) {
            alphabet_cnt_in_word[i][(int)(a - 'a')]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        ans += abs(alphabet_cnt_in_word[0][i] - alphabet_cnt_in_word[1][i]);
    }
    cout << ans << '\n';

    return 0;
}