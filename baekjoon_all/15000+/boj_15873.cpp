#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string AB;
    cin >> AB;

    if ((int)AB.length() == 4) {
        cout << 20 << '\n';
    }
    else if ((int)AB.length() == 2) {
        cout << (AB[0] - '0') + (AB[1] - '0') << '\n';
    }
    else if (AB[1] == '0') {
        cout << AB[0] << AB[2] << '\n';
    }
    else {
        cout << AB[1] << AB[0] << '\n';
    }

    return 0;
}