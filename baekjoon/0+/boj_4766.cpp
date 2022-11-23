#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp

int main() {
    fastio;

    double now_temperature, prev_temperature;
    cin >> prev_temperature;

    while (true) {
        cin >> now_temperature;
        if (now_temperature == 999) {
            break;
        }
        cout << fixed;
        cout.precision(2);
        cout << now_temperature - prev_temperature << '\n';
        prev_temperature = now_temperature;
    }

    return 0;
}