#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;
string output;
stack<char> st;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        char now = input[i];
        if (now >= 'A') {
            output.push_back(now);
        }
        else if (now == '(') {
            // now == '(' : 스택에 넣기
            st.push(now);
        }
        else if (now == ')') {
            // now == ')' : '('까지 스택에서 꺼내기
            while (st.top() != '(') {
                output.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (now == '+' || now == '-') {
            // now == '+', '-' : '+', '-', '*', '/'이 없을 때까지 스택에서 꺼내고 넣기
            while (!st.empty()) {
                char previous = st.top();
                if (previous != '+' && previous != '-' && previous != '*' && previous != '/') {
                    break;
                }
                output.push_back(previous);
                st.pop();
            }
            st.push(now);
        }
        else {
            // now == '*', '/' : '*', '/'이 없을 때까지 스택에서 꺼내고 넣기
            while (!st.empty()) {
                char previous = st.top();
                if (previous != '*' && previous != '/') {
                    break;
                }
                output.push_back(previous);
                st.pop();
            }
            st.push(now);
        }
    }

    while (!st.empty()) {
        output.push_back(st.top());
        st.pop();
    }

    cout << output << '\n';

    return 0;
}