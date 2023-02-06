#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    int limit, speed;
    cin >> limit >> speed;

    if (speed - limit <= 0) {
        cout << "Congratulations, you are within the speed limit!\n";
    }
    else if (speed - limit <= 20) {
        cout << "You are speeding and your fine is $100.\n";
    }
    else if (speed - limit <= 30) {
        cout << "You are speeding and your fine is $270.\n";
    }
    else {
        cout << "You are speeding and your fine is $500.\n";
    }

    return 0;
}