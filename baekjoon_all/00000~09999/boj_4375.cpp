#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int n;
    while (cin >> n) {
        int k = 1, i = 1;
        while (true) {
            if (k % n == 0) break;
            k = (k % n) * 10 + 1;
            i++;
        }
        cout << i << '\n';
    }

    return 0;
}