#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string id0;
    cin >> id0;

    for (int i = 0; i < 9; i++) {
        if (i == 4) {
            cout << ':' << id0 << ':';
        }
        else {
            cout << ":fan:";
        }

        if ((i + 1) % 3 == 0) {
            cout << '\n';
        }
    }

    return 0;
}