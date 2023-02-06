#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

int N;
unordered_map<string, bool> hs;
priority_queue<string> pq;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    for (int n = 0; n < N; n++) {
        string name, log;
        cin >> name >> log;

        if (log == "enter") {
            hs[name] = true;
        }
        else {
            hs[name] = false;
        }
    }

    for (auto it = hs.begin(); it != hs.end(); it++) {
        if (it->second) {
            pq.push(it->first);
        }
    }

    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}