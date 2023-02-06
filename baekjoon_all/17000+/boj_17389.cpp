#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n;
    string s;
    cin >> n >> s;

    int ans = 0, bonus = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') {
            ans += i + 1;
            ans += bonus;
            bonus++;
        }
        else {
            bonus = 0;
        }
    }

    cout << ans << '\n';

    return 0;
}