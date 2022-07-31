#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<int> res;
int N, K;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    int k = 1;

    while (!q.empty()) {
        if (k < K) {
            q.push(q.front());
            q.pop();
            k++;
        }
        else {
            res.push_back(q.front());
            q.pop();
            k = 1;
        }
    }

    cout << '<' << res[0];
    for (int i = 1; i < res.size(); i++) {
        cout << ", " << res[i];
    }
    cout << ">\n";

    return 0;
}