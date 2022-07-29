#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > DP;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    DP.push_back(make_pair(1, 0));
    DP.push_back(make_pair(0, 1));

    for (int i = 2; i <= 40; i++) {
        DP.push_back(make_pair(DP[i - 2].first + DP[i - 1].first, DP[i - 2].second + DP[i - 1].second));
    }

    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        cout << DP[N].first << ' ';
        cout << DP[N].second << '\n';
    }

    return 0;
}