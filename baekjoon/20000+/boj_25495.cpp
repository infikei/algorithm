#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int N, airpods_used_battery;

int main() {
    fastio;

    cin >> N;

    int prev_phone = 0, now_phone, reconnected = 0;

    for (int n = 0; n < N; n++) {
        cin >> now_phone;
        if (now_phone == prev_phone) {
            reconnected++;
        }
        else {
            reconnected = 0;
        }
        airpods_used_battery += (2 << reconnected);
        prev_phone = now_phone;
        if (airpods_used_battery >= 100) {
            airpods_used_battery = 0;
            prev_phone = 0;
            reconnected = 0;
        }
    }

    cout << airpods_used_battery << '\n';

    return 0;
}