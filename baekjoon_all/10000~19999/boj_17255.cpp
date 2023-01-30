#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string N;
int N_size;
unordered_set<string> st;

void dfs(string now = "", int depth = 0, int begin = 0) {
    if (depth == N_size) {
        st.insert(now);
        return;
    }

    // now에 계속 누적해서 쌓아간다.
    // 예시 : 1 -> 11 -> 911 -> 9111이면
    // 1 -> 111 -> 111911 -> 1119119111로 쌓아간 다음
    // set에 1119119111을 저장하는 방식으로 과정을 기록하는 것이다.
    if (begin > 0) {
        dfs(now + N.substr(begin - 1, 1) + now, depth + 1, begin - 1); // 왼쪽에 추가
    }
    if (begin + depth < N_size) {
        dfs(now + now + N.substr(begin + depth, 1), depth + 1, begin); // 오른쪽에 추가
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    N_size = N.length();

    for (int i = 0; i < N_size; i++) {
        dfs(N.substr(i, 1), 1, i);
    }

    cout << st.size() << '\n';

    return 0;
}