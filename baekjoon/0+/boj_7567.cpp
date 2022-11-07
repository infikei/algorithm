#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string dishes;
    cin >> dishes;

    int ans = 10;

    for (int i = 1; i < (int)dishes.length(); i++) {
        if (dishes[i] == dishes[i - 1]) {
            ans += 5;
        }
        else {
            ans += 10;
        }
    }

    cout << ans << '\n';

    return 0;
}