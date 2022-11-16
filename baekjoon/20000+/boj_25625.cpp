#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int x, y;
    cin >> x >> y;

    if (x > y) {
        cout << x + y << '\n';
    }
    else {
        cout << y - x << '\n';
    }

    return 0;
}