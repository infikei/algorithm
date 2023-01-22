#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int score[50], hong, ans;

    for (int i = 0; i < 50; i++) {
        cin >> score[i];
    }

    cin >> hong;
    for (int i = 0; i < 50; i++) {
        if (score[i] == hong) {
            ans = i + 1;
            break;
        }
    }

    if (ans <= 5) cout << "A+\n";
    else if (ans <= 15) cout << "A0\n";
    else if (ans <= 30) cout << "B+\n";
    else if (ans <= 35) cout << "B0\n";
    else if (ans <= 45) cout << "C+\n";
    else if (ans <= 48) cout << "C0\n";
    else cout << "F\n";

    return 0;
}