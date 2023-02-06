#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B;
    cin >> A >> B;
    A--;
    B--;

    int ans = abs(A / 4 - B / 4) + abs(A % 4 - B % 4);
    cout << ans << '\n';

    return 0;
}