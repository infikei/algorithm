#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int standard[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        cout << standard[i] - x << ' ';
    }
    cout << '\n';

    return 0;
}