#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int iter = 1, r, w, l;
    while (true) {
        cin >> r;
        if (r == 0) {
            break;
        }
        cin >> w >> l;

        cout << "Pizza " << iter;
        if (r * r * 4 >= w * w + l * l) {
            cout << " fits on the table.\n";
        }
        else {
            cout << " does not fit on the table.\n";
        }
        iter++;
    }

    return 0;
}