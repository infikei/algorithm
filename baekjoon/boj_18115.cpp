#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int N, cmd[1000000], ans[1000000];
deque<int> dq;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd[i];
    }

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        if (cmd[i] == 1) {
            st.push(dq.front());
            dq.pop_front();
        }
        else if (cmd[i] == 2) {
            int a = dq.front();
            dq.pop_front();
            st.push(dq.front());
            dq.pop_front();
            dq.push_front(a);
        }
        else {
            st.push(dq.back());
            dq.pop_back();
        }
    }

    for (int i = 1; i <= N; i++) {
        ans[st.top()] = i;
        st.pop();
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}