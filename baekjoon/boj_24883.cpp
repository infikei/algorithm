#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    char ch;
    cin >> ch;

    if (ch == 'N' || ch == 'n') {
        cout << "Naver D2\n";
    }
    else {
        cout << "Naver Whale\n";
    }

    return 0;
}