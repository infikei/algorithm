#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, K;
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    int ans[1001];
    int ans_size = 0, pop = K, person;

    while (!q.empty()) {
        person = q.front();
        q.pop();

        if (pop == 1) {
            ans[ans_size] = person;
            ans_size++;
            pop = K;
        }
        else {
            q.push(person);
            pop--;
        }
    }

    cout << '<' << ans[0];
    for (int i = 1; i < N; i++)
        cout << ", " << ans[i];
    cout << ">\n";

    return 0;
}