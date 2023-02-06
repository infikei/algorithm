#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    while (true) {
        int M, F;
        cin >> M >> F;
        if (M == 0 && F == 0) {
            break;
        }
        cout << M + F << '\n';
    }

    return 0;
}