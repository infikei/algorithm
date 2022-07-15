#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> p;
vector<p> schedule;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    int start, finish;

    for (int i = 0; i < N; i++) {
        cin >> start >> finish;
        schedule.push_back(make_pair(finish, start));
    }

    sort(schedule.begin(), schedule.end());

    int ans = 1, now = schedule[0].first;
    for (int i = 1; i < N; i++) {
        if (schedule[i].second >= now) {
            ans++;
            now = schedule[i].first;
        }
    }

    cout << ans << '\n';

    return 0;
}