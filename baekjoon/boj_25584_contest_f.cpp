#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int time_work[4] = {4, 6, 4, 10};
unordered_map<string, int> hs;
int hs_sz;
vector<int> time_sum;

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
                if (hs_sz < 5000 && hs.find(input) == hs.end()) {
                    hs[input] = hs_sz;
                    hs_sz++;
                    time_sum.push_back(time_work[i]);
                    continue;
                }
                time_sum[hs[input]] += time_work[i];
            }
        }
    }

    
    if (time_sum.empty()) {
        cout << "Yes" << '\n';
    }
    else {
        sort(time_sum.begin(), time_sum.end());

        if (time_sum[(int)time_sum.size() - 1] - time_sum[0] <= 12) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}