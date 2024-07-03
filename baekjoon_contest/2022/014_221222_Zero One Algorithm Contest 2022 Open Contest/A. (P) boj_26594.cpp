#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N;
string input;

int main() {
    fastio;

    cin >> input;

    for (auto a : input) {
        if (a == input[0]) N++;
        else break;
    }

    cout << N << '\n';

    return 0;
}