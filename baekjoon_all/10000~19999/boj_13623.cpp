#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B, C;
    cin >> A >> B >> C;

    if (A == B) {
        if (B == C) {
            cout << '*';
        }
        else {
            cout << 'C';
        }
    }
    else {
        if (B == C) {
            cout << 'A';
        }
        else {
            cout << 'B';
        }
    }
    cout << '\n';

    return 0;
}