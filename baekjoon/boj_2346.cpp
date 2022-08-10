#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef pair<int, int> pii;

int N;
deque<pii> dq;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;

    int num;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        dq.push_back(make_pair(i, num));
    }

    for (int i = 0; i < N; i++) {
        v.push_back(dq.front().first);
        num = dq.front().second;
        dq.pop_front();

        if (dq.empty()) {
            break;
        }

        if (num > 0) {
            for (int j = 0; j < num - 1; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            num *= -1;
            for (int j = 0; j < num; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}