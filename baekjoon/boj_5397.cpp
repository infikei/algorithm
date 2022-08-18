#include <iostream>
#include <string>
#include <stack>
using namespace std;

int K;
string input, ans;
stack<char> st_left, st_right;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> K;

    for (int k = 0; k < K; k++) {
        cin >> input;
        int input_size = input.length();

        for (int i = 0; i < input_size; i++) {
            char now = input[i];
            if (now == '<') {
                if (!st_left.empty()) {
                    st_right.push(st_left.top());
                    st_left.pop();
                }
            }
            else if (now == '>') {
                if (!st_right.empty()) {
                    st_left.push(st_right.top());
                    st_right.pop();
                }
            }
            else if (now == '-') {
                if (!st_left.empty()) {
                    st_left.pop();
                }
            }
            else {
                st_left.push(now);
            }
        }

        while (!st_left.empty()) {
            st_right.push(st_left.top());
            st_left.pop();
        }

        ans = "";

        while (!st_right.empty()) {
            ans += st_right.top();
            st_right.pop();
        }

        cout << ans << '\n';
    }

    return 0;
}