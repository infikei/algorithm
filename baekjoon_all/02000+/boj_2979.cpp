#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int cost[4] = {0};
    for (int i = 1; i <= 3; i++) {
        cin >> cost[i];
        cost[i] *= i;
    }

    int check_arr[100] = {0};
    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            check_arr[j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i < 100; i++) {
        ans += cost[check_arr[i]];
    }
    cout << ans << '\n';

    return 0;
}