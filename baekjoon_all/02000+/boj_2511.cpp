#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int cards[2][10];

int main() {
    fastio;

    for (int person = 0; person < 2; person++) {
        for (int i = 0; i < 10; i++) {
            cin >> cards[person][i];
        }
    }

    int Ascore = 0, Bscore = 0, last_win = 3;
    for (int i = 0; i < 10; i++) {
        if (cards[0][i] > cards[1][i]) {
            Ascore += 3;
            last_win = 0;
        }
        else if (cards[0][i] < cards[1][i]) {
            Bscore += 3;
            last_win = 1;
        }
        else {
            Ascore += 1;
            Bscore += 1;
        }
    }

    cout << Ascore << ' ' << Bscore << '\n';
    if (Ascore > Bscore) {
        cout << "A\n";
    }
    else if (Ascore < Bscore) {
        cout << "B\n";
    }
    else {
        cout << (char)('A' + last_win) << '\n';
    }

    return 0;
}