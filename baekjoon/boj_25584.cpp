#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> hs;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    string input;
    for (int week = 0; week < N; week++) {
        for (int i = 0; i < 4; i++) {
            for (int day = 0; day < 7; day++) {
                cin >> input;
                if (input == "-") {
                    continue;
                }
                if (hs.find(input) == hs.end()) {
                    if (i == 1) {
                        hs.insert(make_pair(input, 6));
                    }
                    else if (i == 3) {
                        hs.insert(make_pair(input, 10));
                    }
                    else {
                        hs.insert(make_pair(input, 4));
                    }
                    continue;
                }

                if (i == 1) {
                    hs[input] += 6;
                }
                else if (i == 3) {
                    hs[input] += 10;
                }
                else {
                    hs[input] += 4;
                }
            }
        }
    }

    if (hs.empty()) {
        cout << "Yes" << '\n';
    }
    else {
        int hs_min = 5000 * 7 * 24, hs_max = 0;

        for (auto it = hs.begin(); it != hs.end(); it++) {
            if (it->second < hs_min) {
                hs_min = it->second;
            }
            if (it->second > hs_max) {
                hs_max = it->second;
            }
        }

        if (hs_max - hs_min <= 12) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}