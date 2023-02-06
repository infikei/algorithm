#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string S1, S2;
        cin >> S1 >> S2;

        cout << "Distances:";
        int i_end = S1.length();
        for (int i = 0; i < i_end; i++) {
            if (S1[i] <= S2[i]) {
                cout << ' ' << S2[i] - S1[i];
            }
            else {
                cout << ' ' << S2[i] + 26 - S1[i];
            }
        }
        cout << '\n';
    }

    return 0;
}