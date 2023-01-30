#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    string s;
    cin >> s;

    int hand = 0, ans[2] = {0};
    for (auto a : s) {
        if (a == '=') continue;
        else if (a == '@') ans[hand]++;
        else if (a == '(') hand = 1;
    }

    cout << ans[0] << ' ' << ans[1] << '\n';

    return 0;
}