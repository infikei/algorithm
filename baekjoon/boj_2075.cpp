#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, x;
    priority_queue<int, vector<int>, greater<int> > pq_min; // 최솟값이 top에 있는 우선순위 큐

    cin >> N;

    // 첫 줄에 적혀있는 N개의 수를 우선순위 큐에 넣어서 size = N일 때까지 채운다.
    for (int j = 0; j < N; j++) {
        cin >> x;
        pq_min.push(x);
    }

    // 두번째 줄부터 입력받은 수가 top에 있는 값보다 클 경우에 우선순위 큐에 넣고 이후 최솟값을 다시 제거한다.
    // 문제에 메모리 제한이 걸려있으므로 size = N으로 유지해야 한다.
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            if (x > pq_min.top()) {
                pq_min.push(x);
                pq_min.pop();
            }
        }
    }

    cout << pq_min.top() << '\n';

    return 0;
}