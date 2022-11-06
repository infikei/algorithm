#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int T;
    cin >> T;

    int A[10];

    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 10; i++) {
            cin >> A[i];
        }
        sort(A, A + 10, greater<int>());
        cout << A[2] << '\n';
    }

    return 0;
}