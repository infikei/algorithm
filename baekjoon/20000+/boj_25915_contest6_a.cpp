#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    char start;
    cin >> start;

    int ans = 84 + abs(start - 'I');
    cout << ans << '\n';

    return 0;
}