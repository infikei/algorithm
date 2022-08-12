#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define sz(v) ((int)v.size())

int N, input_values[26];
string input_expression;
stack<double> st;

void input() {
    cin >> N >> input_expression;
    for (int i = 0; i < N; i++) {
        cin >> input_values[i];
    }
}

void solve() {
    int input_expression_size = sz(input_expression);
    for (int i = 0; i < input_expression_size; i++) {
        char now = input_expression[i];
        if (now >= 'A' && now <= 'Z') {
            st.push(input_values[now - 'A']);
        }
        else if (now == '+') {
            double temp = st.top();
            st.pop();
            temp = st.top() + temp;
            st.pop();
            st.push(temp);
        }
        else if (now == '-') {
            double temp = st.top();
            st.pop();
            temp = st.top() - temp;
            st.pop();
            st.push(temp);
        }
        else if (now == '*') {
            double temp = st.top();
            st.pop();
            temp = st.top() * temp;
            st.pop();
            st.push(temp);
        }
        else if (now == '/') {
            double temp = st.top();
            st.pop();
            temp = st.top() / temp;
            st.pop();
            st.push(temp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';

    return 0;
}