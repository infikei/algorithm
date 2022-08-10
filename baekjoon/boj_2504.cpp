#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;
bool input_check = true;
int ans;
stack<char> st;
stack<int> st2;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
                st.push('*');
                st2.push(2);
                continue;
            }

            int inner_value = 0;
            while (!st.empty() && st.top() == '*') {
                inner_value += st2.top();
                st.pop();
                st2.pop();
            }
            if (st.empty() || st.top() != '(') {
                input_check = false;
                break;
            }
            st.pop();
            st.push('*');
            st2.push(inner_value * 2);
        }
        else if (input[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
                st.push('*');
                st2.push(3);
                continue;
            }

            int inner_value = 0;
            while (!st.empty() && st.top() == '*') {
                inner_value += st2.top();
                st.pop();
                st2.pop();
            }
            if (st.empty() || st.top() != '[') {
                input_check = false;
                break;
            }
            st.pop();
            st.push('*');
            st2.push(inner_value * 3);
        }
        else {
            st.push(input[i]);
        }
    }

    ans = 0;

    if (input_check) {
        while (!st.empty()) {
            if (st.top() == '*') {
                ans += st2.top();
                st.pop();
                st2.pop();
            }
            else {
                input_check = false;
                ans = 0;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}