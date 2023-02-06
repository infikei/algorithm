#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string numbers;
    cin >> numbers;

    if (numbers.substr(0, 3) == "555") {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}