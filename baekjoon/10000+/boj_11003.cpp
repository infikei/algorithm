#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef pair<int, int> pii;

deque<pii> DQ;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        while (!DQ.empty() && i > DQ.front().second) {
            DQ.pop_front();
        }

        while (!DQ.empty() && a <= DQ.back().first) {
            DQ.pop_back();
        }

        DQ.push_back(make_pair(a, i + L - 1));

        cout << DQ.front().first << ' ';
    }

    return 0;
}