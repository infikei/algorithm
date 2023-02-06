#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int cnt[101];
int avr, most_cnt, most_val;

int main() {
    fastio;

    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        x /= 10;
        avr += x;
        cnt[x]++;
    }

    for (int i = 1; i < 101; i++) {
        if (cnt[i] > most_cnt) {
            most_cnt = cnt[i];
            most_val = i * 10;
        }
    }

    cout << avr << '\n';
    cout << most_val << '\n';

    return 0;
}