#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using ll = long long;

int main() {
    fastio;

    ll N;
    cin >> N;

    string ans;
    while (N > 0) {
        ans = (char)('0' + (N % 2)) + ans;
        N /= 2;
    }

    cout << ans << '\n';

    return 0;
}