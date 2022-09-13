#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int N, ans = 0;
int arr[4];

int calc() {
    pii cnt[7];

    for (int i = 0; i <= 6; i++) {
        cnt[i] = make_pair(0, i);
    }

    for (int i = 0; i < 4; i++) {
        (cnt[arr[i]].first)++;
    }

    sort(cnt, cnt + 7);

    if (cnt[6].first == 4) {
        return 50000 + cnt[6].second * 5000;
    }
    else if (cnt[6].first == 3) {
        return 10000 + cnt[6].second * 1000;
    }
    else if (cnt[6].first == 2) {
        if (cnt[5].first == 2) {
            return 2000 + cnt[5].second * 500 + cnt[6].second * 500;
        }
        else {
            return 1000 + cnt[6].second * 100;
        }
    }
    else {
        return cnt[6].second * 100;
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    
    cin >> N;

    for (int n = 0; n < N; n++) {
        for (int i = 0; i < 4; i++) {
            cin >> arr[i];
        }

        ans = max(ans, calc());
    }

    cout << ans << '\n';

    return 0;
}