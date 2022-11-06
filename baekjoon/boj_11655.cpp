#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string S;
    getline(cin, S);

    for (int i = 0; i < (int)S.length(); i++) {
        if (S[i] >= 'A' && S[i] <= 'M') {
            S[i] += 13;
        }
        else if (S[i] >= 'N' && S[i] <= 'Z') {
            S[i] -= 13;
        }
        else if (S[i] >= 'a' && S[i] <= 'm') {
            S[i] += 13;
        }
        else if (S[i] >= 'n' && S[i] <= 'z') {
            S[i] -= 13;
        }
    }

    cout << S << '\n';

    return 0;
}