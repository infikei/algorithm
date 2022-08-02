// 메모 : 첫 골드4 문제, 진짜 힘들었다.. 다행히 1트 만에 성공 . . !
// 이 문제는 결국 스택을 잘 활용해서 풀어야 하는 문제였는데,
// 값을 저장하는 스택(st) 그리고 인덱스 값을 저장하는 스택(st_index)을 하나 더 사용해서 해결했다.
// 답을 저장할 배열(ans)도 하나 더 사용해야 했다. 더 좋은 방법이 있을까..?

// 예시 : 9 5 6 ... 라고 하자.
// 0번째 값 9는 일단 스택에 저장한다.
// st = {9}, st_index = {0}
// 1번째 값 5이 들어온다. st.top() = 9는 input = 5보다 크므로 추가 작업 없이 5를 스택에 저장한다.
// st = {9, 5}, st_index = {0, 1}
// 2번째 값 6이 들어온다. st.top() = 5는 input = 6보다 작으므로 스택에서 5를 꺼낸다.
// 동시에 ans[st_index.top()] = ans[1]에 input 값 6을 저장한다.
// st.top() = 9는 input = 6보다 크므로 추가 작업 없이 6을 스택에 저장한다.

// 이 작업을 계속 하다보면 st에 남아있는 값은 내림차순이 된다는 것이 포인트였다.
// input 값을 모두 받은 후에는 스택에서 꺼내지 못한 값들의 index 값들이 st_index에 남아있을 것이다.
// 이를 이용하면 ans 배열에 빈 곳을 -1으로 채워줄 수 있다.

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, input;
    cin >> N;

    stack<int> st;
    stack<int> st_index;
    int ans[1000001];

    cin >> input;
    st.push(input);
    st_index.push(0);

    for (int input_index = 1; input_index < N; input_index++) {
        cin >> input;
        while (st.top() < input) {
            ans[st_index.top()] = input;
            st.pop();
            st_index.pop();
            if (st.empty())
                break;
        }
        st.push(input);
        st_index.push(input_index);
    }

    while (!st_index.empty()) {
        ans[st_index.top()] = -1;
        st_index.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}