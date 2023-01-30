#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string S;
    cin >> S;

    int cnt = 0;
    char prev_ch = '2';
    for (auto a : S) {
        if (a != prev_ch) {
            cnt++;
            prev_ch = a;
        }
    }

    cout << cnt / 2 << '\n';

    return 0;
}