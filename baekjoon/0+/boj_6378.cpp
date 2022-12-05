#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string S;
    int ans;

    while (true) {
        cin >> S;
        if (S == "0") {
            break;
        }

        ans = 0;
        for (auto s : S) {
            ans += (int)(s - '0');
        }

        while (ans > 9) {
            S = to_string(ans);
            ans = 0;
            for (auto s : S) {
                ans += (int)(s - '0');
            }
        }

        cout << ans << '\n';
    }

    return 0;
}