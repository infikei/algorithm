#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int T, S;
    cin >> T >> S;
    cout << ((S == 0 && T >= 12 && T <= 16) ? 320 : 280) << '\n';

    return 0;
}