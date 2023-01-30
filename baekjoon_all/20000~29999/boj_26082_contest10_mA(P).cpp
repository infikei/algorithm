#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B, C;
    cin >> A >> B >> C;

    int ans = B / A * C * 3;
    cout << ans << '\n';

    return 0;
}