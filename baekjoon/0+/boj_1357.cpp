#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string X, Y, ans;
    cin >> X >> Y;
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());

    ans = to_string(stoi(X) + stoi(Y));
    reverse(ans.begin(), ans.end());
    ans = to_string(stoi(ans));

    cout << ans << '\n';

    return 0;
}