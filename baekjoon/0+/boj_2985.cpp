#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int A, B, C;
    cin >> A >> B >> C;

    if (A + B == C) {
        cout << A << '+' << B << '=' << C << '\n';
    }
    else if (A - B == C) {
        cout << A << '-' << B << '=' << C << '\n';
    }
    else if (A * B == C) {
        cout << A << '*' << B << '=' << C << '\n';
    }
    else if (A / B == C) {
        cout << A << '/' << B << '=' << C << '\n';
    }
    else if (A == B + C) {
        cout << A << '=' << B << '+' << C << '\n';
    }
    else if (A == B - C) {
        cout << A << '=' << B << '-' << C << '\n';
    }
    else if (A == B * C) {
        cout << A << '=' << B << '*' << C << '\n';
    }
    else {
        cout << A << '=' << B << '/' << C << '\n';
    }

    return 0;
}