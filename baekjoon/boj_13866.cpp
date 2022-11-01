#include <iostream>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int skills[4];
    for (int i = 0; i < 4; i++) {
        cin >> skills[i];
    }

    sort(skills, skills + 4);
    int ans = skills[0] + skills[3] - skills[1] - skills[2];
    if (ans < 0) {
        ans = -ans;
    }
    cout << ans << '\n';

    return 0;
}