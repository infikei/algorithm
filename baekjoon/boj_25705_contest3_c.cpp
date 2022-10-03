#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, cnt;
string S0, S;
vector<int> V[26];

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N >> S0;
    cin >> M >> S;

    for (int i = 0; i < N; i++) {
        V[S0[i] - 'a'].push_back(i);
    }

    int prev_idx = N - 1;

    for (int i = 0; i < M; i++) {
        int now_ch = S[i] - 'a';

        // if S[i] is not in S0, break
        if (V[now_ch].empty()) {
            cnt = -1;
            break;
        }

        // initialize diff
        int diff = V[now_ch][0] - prev_idx;
        if (diff <= 0) {
            diff += N;
        }

        // calculate diff
        for (auto v : V[now_ch]) {
            int diff2 = v - prev_idx;
            if (diff2 <= 0) {
                diff2 += N;
            }
            diff = min(diff, diff2);
        }

        cnt += diff;
        prev_idx += diff;
        if (prev_idx >= N) {
            prev_idx -= N;
        }
    }

    cout << cnt << '\n';

    return 0;
}