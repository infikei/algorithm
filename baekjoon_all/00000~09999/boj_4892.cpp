#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int iter = 0;
    while (true) {
        int n0;
        cin >> n0;
        if (n0 == 0) {
            break;
        }
        iter++;

        cout << iter;
        if (n0 % 2 == 0) {
            cout << ". even ";
        }
        else {
            cout << ". odd ";
        }
        cout << n0 / 2 << '\n';
    }

    return 0;
}