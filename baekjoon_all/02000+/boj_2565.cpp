#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<pii> A_to_B;
int DP[500];
int N, ans;

void input() {
    cin >> N;
    int A, B;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        A_to_B.push_back(make_pair(A, B));
    }
    sort(A_to_B.begin(), A_to_B.end());
}

void dp() {
    DP[0] = 1;
    ans = 1;

    for (int i = 1; i < N; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A_to_B[j].second < A_to_B[i].second) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        ans = max(ans, DP[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    dp();

    cout << (N - ans) << '\n';

    return 0;
}