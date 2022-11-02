#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string line;
    getline(cin, line);

    stringstream ss(line);
    string line_split[5];
    for (int i = 0; i < 5; i++) {
        ss >> line_split[i];
    }

    if (stoi(line_split[0]) + stoi(line_split[2]) == stoi(line_split[4])) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}