#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        string S;
        cin >> S;

        int S_len2 = S.length() / 2;
        if (S[S_len2 - 1] == S[S_len2]) {
            cout << "Do-it\n";
        }
        else {
            cout << "Do-it-Not\n";
        }
    }

    return 0;
}