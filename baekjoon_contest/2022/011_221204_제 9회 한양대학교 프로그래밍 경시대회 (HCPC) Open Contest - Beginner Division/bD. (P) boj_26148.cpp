#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int YYYY, d;
    cin >> YYYY >> d;

    bool flag_exists_feb_29 = false;

    if (YYYY % 4 == 0) {
        if (YYYY % 100 != 0 || YYYY % 400 == 0) {
            flag_exists_feb_29 = true;
        }
    }

    if (flag_exists_feb_29) {
        cout << 30 << '\n';
    }
    else {
        cout << 29 << '\n';
    }

    return 0;
}