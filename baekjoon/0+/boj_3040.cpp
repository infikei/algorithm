#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int numbers[9], numbers_sum;
int check_idx[2];

void check_the_idx() {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (numbers[i] + numbers[j] + 100 == numbers_sum) {
                check_idx[0] = i;
                check_idx[1] = j;
                return;
            }
        }
    }
}

int main() {
    fastio;

    for (int i = 0; i < 9; i++) {
        cin >> numbers[i];
        numbers_sum += numbers[i];
    }

    check_the_idx();

    for (int i = 0; i < 9; i++) {
        if (i == check_idx[0] || i == check_idx[1]) {
            continue;
        }
        cout << numbers[i] << '\n';
    }

    return 0;
}