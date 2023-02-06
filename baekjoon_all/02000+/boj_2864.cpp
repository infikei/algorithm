#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string A5, B5, A6, B6;
    cin >> A5 >> B5;
    A6 = A5;
    B6 = B5;

    for (int i = 0; i < (int)A5.length(); i++) {
        if (A5[i] == '5' || A5[i] == '6') {
            A5[i] = '5';
            A6[i] = '6';
        }
    }
    for (int i = 0; i < (int)B5.length(); i++) {
        if (B5[i] == '5' || B5[i] == '6') {
            B5[i] = '5';
            B6[i] = '6';
        }
    }

    cout << stoi(A5) + stoi(B5) << ' ' << stoi(A6) + stoi(B6) << '\n';

    return 0;
}