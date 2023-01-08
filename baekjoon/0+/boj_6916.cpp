#include <iostream>
#include <string>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

string s[5] = {"", "*", "      *", "*     *", " * * *"};

void print(int type, int iter = 1) {
    for (int i = 0; i < iter; i++) {
        cout << s[type] << '\n';
    }
}

int main() {
    fastio;

    int n;
    cin >> n;

    if (n == 0) {
        print(4); print(3, 3); print(0); print(3, 3); print(4);
    }
    else if (n == 1) {
        print(0); print(2, 3); print(0); print(2, 3);
    }
    else if (n == 2) {
        print(4); print(2, 3); print(4); print(1, 3); print(4);
    }
    else if (n == 3) {
        print(4); print(2, 3); print(4); print(2, 3); print(4);
    }
    else if (n == 4) {
        print(0); print(3, 3); print(4); print(2, 3);
    }
    else if (n == 5) {
        print(4); print(1, 3); print(4); print(2, 3); print(4);
    }
    else if (n == 6) {
        print(4); print(1, 3); print(4); print(3, 3); print(4);
    }
    else if (n == 7) {
        print(4); print(2, 3); print(0); print(2, 3);
    }
    else if (n == 8) {
        print(4); print(3, 3); print(4); print(3, 3); print(4);
    }
    else if (n == 9) {
        print(4); print(3, 3); print(4); print(2, 3); print(4);
    }

    return 0;
}