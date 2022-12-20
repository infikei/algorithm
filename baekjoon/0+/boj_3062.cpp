#include <iostream>
#include <string>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int T, N, S_len;
string S;
bool check;

int main() {
    fastio;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        S = to_string(N);
        reverse(S.begin(), S.end());
        N += stoi(S);
        S = to_string(N);
        S_len = S.length();
        check = true;
        for (int i = 0; i < S_len / 2; i++) {
            if (S[i] != S[S_len - 1 - i]) {
                check = false;
                break;
            }
        }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}