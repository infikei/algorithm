#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int K;
        cin >> K;

        for (int k = 0; k < K; k++) {
            cout << '=';
        }
        cout << '\n';
    }

    return 0;
}