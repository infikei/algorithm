#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string S;
    cin >> S;

    int ans = 0;

    stringstream ss(S);

    while (true) {
        string s;
        getline(ss, s, ',');
        if (s == "") {
            break;
        }
        ans += stoi(s);
    }

    cout << ans << '\n';

    return 0;
}