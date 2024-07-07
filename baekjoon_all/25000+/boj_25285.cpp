// Solve 2024-07-06

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t-- > 0) {
        int cm, kg;
        cin >> cm >> kg;

        if (cm <= 140) {
            cout << 6 << '\n';
        }
        else if (cm < 146) {
            cout << 5 << '\n';
        }
        else if (cm < 159) {
            cout << 4 << '\n';
        }
        else if (cm < 161) {
            if (kg * 10000 < cm * cm * 16 || kg * 10000 >= cm * cm * 35) {
                cout << 4 << '\n';
            }
            else {
                cout << 3 << '\n';
            }
        }
        else if (cm < 204) {
            if (kg * 10000 < cm * cm * 16 || kg * 10000 >= cm * cm * 35) {
                cout << 4 << '\n';
            }
            else if (kg * 20000 < cm * cm * 37 || kg * 10000 >= cm * cm * 30) {
                cout << 3 << '\n';
            }
            else if (kg * 10000 < cm * cm * 20 || kg * 10000 >= cm * cm * 25) {
                cout << 2 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else {
            cout << 4 << '\n';
        }
    }

    return 0;
}
