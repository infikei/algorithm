#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N, cnt;
string word;
stack<char> st;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    cnt = 0;

    for (int n = 0; n < N; n++) {
        // st 초기화
        while (!st.empty()) {
            st.pop();
        }

        cin >> word;
        for (int i = 0; i < word.length(); i++) {
            if (!st.empty() && st.top() == word[i]) {
                st.pop();
            }
            else {
                st.push(word[i]);
            }
        }

        if (st.empty()) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}