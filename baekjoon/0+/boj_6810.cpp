#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int sum_of_num[2] = {28, 21};
    for (int i = 0; i < 3; i++) {
        int x;
        cin >> x;
        sum_of_num[i % 2] += x;
    }

    int ans = sum_of_num[0] + sum_of_num[1] * 3;
    cout << "The 1-3-sum is " << ans << '\n';

    return 0;
}