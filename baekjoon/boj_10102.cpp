#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int cnt[2];

int main() {
    fastio;

    int V;
    cin >> V;

    string vote;
    cin >> vote;

    for (auto a : vote) {
        cnt[a - 'A']++;
    }

    if (cnt[0] > cnt[1]) {
        cout << "A\n";
    }
    else if (cnt[0] < cnt[1]) {
        cout << "B\n";
    }
    else {
        cout << "Tie\n";
    }

    return 0;
}