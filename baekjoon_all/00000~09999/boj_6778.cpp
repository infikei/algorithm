#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int antenna, eyes;
    cin >> antenna >> eyes;

    if (antenna >= 3 && eyes <= 4) {
        cout << "TroyMartian\n";
    }
    if (antenna <= 6 && eyes >= 2) {
        cout << "VladSaturnian\n";
    }
    if (antenna <= 2 && eyes <= 3) {
        cout << "GraemeMercurian\n";
    }

    return 0;
}