#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        string cmd;
        cin >> cmd;

        int num_size;
        string num_str, temp_str = "";
        cin >> num_size;
        cin >> num_str;

        deque<int> dq;
        for (int i = 0; i < num_str.length(); i++) {
            if (isdigit(num_str[i])) {
                temp_str += num_str[i];
            }
            else {
                if (!temp_str.empty()) {
                    dq.push_back(stoi(temp_str));
                    temp_str = "";
                }
            }
        }

        bool reverse = false, error = false;

        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R') {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else if (cmd[i] == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                else if (reverse) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }
        if (dq.empty()) {
            cout << "[]\n";
        }
        else if (reverse) {
            int dq_size = dq.size();
            cout << '[' << dq[dq_size - 1];
            for (int i = 1; i < dq_size; i++) {
                cout << ',' << dq[dq_size - 1 - i];
            }
            cout << "]\n";
        }
        else {
            int dq_size = dq.size();
            cout << '[' << dq[0];
            for (int i = 1; i < dq_size; i++) {
                cout << ',' << dq[i];
            }
            cout << "]\n";
        }
    }

    return 0;
}