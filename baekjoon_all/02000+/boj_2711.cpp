#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int idx;
        string S;
        cin >> idx >> S;
        S.erase(S.begin() + (idx - 1), S.begin() + idx);
        cout << S << '\n';
    }

    return 0;
}