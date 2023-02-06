#include <iostream>
#include <string>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    string now_time, target_time;
    cin >> now_time >> target_time;

    int now_time_int = stoi(now_time.substr(0, 2)) * 3600 + stoi(now_time.substr(3, 2)) * 60 + stoi(now_time.substr(6, 2));
    int target_time_int = stoi(target_time.substr(0, 2)) * 3600 + stoi(target_time.substr(3, 2)) * 60 + stoi(target_time.substr(6, 2));

    if (target_time_int <= now_time_int) {
        target_time_int += 86400;
    }

    int waiting_time_int = target_time_int - now_time_int;
    int h = waiting_time_int / 3600;
    int m = (waiting_time_int % 3600) / 60;
    int s = waiting_time_int % 60;
    if (h < 10) {
        cout << 0;
    }
    cout << h << ':';
    if (m < 10) {
        cout << 0;
    }
    cout << m << ':';
    if (s < 10) {
        cout << 0;
    }
    cout << s;

    return 0;
}