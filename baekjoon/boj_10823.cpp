#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

string S;

int main() {
    fastio;

    string S;

    while (true) {
        string tmp;
        cin >> tmp;
        if (tmp == "") {
            break;
        }
        S += tmp;
    }

    stringstream ss(S);
    int ans = 0;

    while (true) {
        string tmp;
        getline(ss, tmp, ',');
        if (tmp == "") {
            break;
        }
        ans += stoi(tmp);
    }

    cout << ans << '\n';

    return 0;
}