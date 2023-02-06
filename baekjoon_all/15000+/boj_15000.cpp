#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string S;
    cin >> S;

    for (auto ch : S) {
        cout << (char)(ch - 'a' + 'A');
    }
    cout << '\n';

    return 0;
}