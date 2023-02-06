#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;

struct cmp {
    bool operator()(pii a, pii b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

struct cmp2 {
    bool operator()(pii a, pii b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

unordered_map<int, int> hs;
priority_queue<pii, vector<pii>, cmp > pq_max;
priority_queue<pii, vector<pii>, cmp2> pq_min;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int P, L;
        cin >> P >> L;
        hs[P] = L;
        pq_max.push(make_pair(P, L));
        pq_min.push(make_pair(P, L));
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "recommend") {
            int x;
            cin >> x;

            if (x == 1) {
                // 가장 어려운 문제의 번호를 출력
                while (hs[pq_max.top().first] != pq_max.top().second) {
                    pq_max.pop();
                }

                cout << pq_max.top().first << '\n';
            }
            else {
                // 가장 쉬운 문제의 번호를 출력
                while (hs[pq_min.top().first] != pq_min.top().second) {
                    pq_min.pop();
                }

                cout << pq_min.top().first << '\n';
            }
        }
        else if (cmd == "add") {
            int P, L;
            cin >> P >> L;
            hs[P] = L;
            pq_max.push(make_pair(P, L));
            pq_min.push(make_pair(P, L));
        }
        else {
            int P;
            cin >> P;
            hs[P] = -1;
        }
    }

    return 0;
}