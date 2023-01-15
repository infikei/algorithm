#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int a, b, c, n;
bool check;

int main() {
    fastio;

    cin >> a >> b >> c >> n;

    for (int i = 0; i <= n; i += c) {
        for (int j = 0; j <= n - i; j += b) {
            if ((n - i - j) % a == 0) {
                check = true;
                break;
            }
        }
        if (check) break;
    }

    if (check) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}