#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int ten;
    cin >> ten;

    string nine;
    char ch;
    while (ten > 0) {
        ch = '0' + ten % 9;
        nine = ch + nine;
        ten /= 9;
    }
    cout << nine << '\n';

    return 0;
}