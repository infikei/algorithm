#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string S;
    cin >> S;

    stringstream ss(S);
    string part;
    int cnt = 0;
    while (getline(ss, part, ',')) {
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}