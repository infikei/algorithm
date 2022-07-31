#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> score;
vector<int> final_problems;
int final_score;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    // 입력
    int score_input;
    for (int problem = 1; problem <= 8; problem++) {
        cin >> score_input;
        score.push_back(make_pair(score_input, problem));
    }

    // 계산
    sort(score.begin(), score.end(), greater<pii>());
    final_score = 0;
    for (int i = 0; i < 5; i++) {
        final_score += score[i].first;
        final_problems.push_back(score[i].second);
    }
    sort(final_problems.begin(), final_problems.end());

    // 출력
    cout << final_score << '\n';
    for (int i = 0; i < 5; i++) {
        cout << final_problems[i] << ' ';
    }
    cout << '\n';

    return 0;
}