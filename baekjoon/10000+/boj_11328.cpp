#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string S[2];
        int cnt[2][26] = {0};

        for (int i = 0; i < 2; i++) {
            cin >> S[i];
            for (auto c : S[i]) {
                cnt[i][c - 'a']++;
            }
        }

        bool flag = true;
        for (int j = 0; j < 26; j++) {
            if (cnt[0][j] != cnt[1][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Possible\n";
        }
        else {
            cout << "Impossible\n";
        }
    }

    return 0;
}