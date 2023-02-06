#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int T;
    cin >> T;

    string s[2];

    for (int t = 0; t < T; t++) {
        cin >> s[0] >> s[1];

        int i_end = s[0].length(), ans = 0;
        for (int i = 0; i < i_end; i++) {
            if (s[0][i] != s[1][i]) {
                ans++;
            }
        }

        cout << "Hamming distance is " << ans << ".\n";
    }

    return 0;
}