#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int N;
    cin >> N;

    int ans = 1;
    while (ans * 2 <= N) ans *= 2;
    cout << ans << '\n';

    return 0;
}