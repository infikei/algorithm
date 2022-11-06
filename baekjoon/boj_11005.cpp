#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int N, B;
    cin >> N >> B;

    string ans;

    while (N > 0) {
        if (N % B > 9) {
            ans = (char)('A' + N % B - 10) + ans;
        }
        else {
            ans = (char)('0' + N % B) + ans;
        }

        N /= B;
    }

    cout << ans << '\n';

    return 0;
}