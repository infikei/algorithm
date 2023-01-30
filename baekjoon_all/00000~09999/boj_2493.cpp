#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pii;

int N, arr[500001];
stack<pii> st;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int now = arr[i];
        int now_output = 0;
        while (!st.empty() && st.top().second < now) {
            st.pop();
        }
        now_output = (st.empty() ? 0 : st.top().first);
        cout << now_output << ' ';
        st.push(make_pair(i, now));
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    return 0;
}