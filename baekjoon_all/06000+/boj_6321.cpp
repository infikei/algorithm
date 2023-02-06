#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) {
        string S;
        cin >> S;

        int S_len = S.length();
        for (int i = 0; i < S_len; i++) {
            if (S[i] == 'Z') {
                S[i] = 'A';
            }
            else {
                S[i]++;
            }
        }

        if (n > 1) {
            cout << '\n';
        }
        cout << "String #" << n << '\n';
        cout << S << '\n';
    }

    return 0;
}