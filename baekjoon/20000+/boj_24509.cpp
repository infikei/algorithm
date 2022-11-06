#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int N, ans[4];
vector<pii> A, B, C, D;

bool cmp(const pii &a, const pii &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int idx, score;
        cin >> idx;
        cin >> score;
        A.push_back(make_pair(idx, score));
        cin >> score;
        B.push_back(make_pair(idx, score));
        cin >> score;
        C.push_back(make_pair(idx, score));
        cin >> score;
        D.push_back(make_pair(idx, score));
    }

    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    sort(C.begin(), C.end(), cmp);
    sort(D.begin(), D.end(), cmp);
}

void print() {
    ans[0] = A[0].first;
    ans[1] = B[0].first;
    if (ans[1] == ans[0]) {
        ans[1] = B[1].first;
    }
    ans[2] = C[0].first;
    for (int i = 1; i <= 2; i++) {
        if (ans[2] == ans[1] || ans[2] == ans[0]) {
            ans[2] = C[i].first;
        }
        else {
            break;
        }
    }
    ans[3] = D[0].first;
    for (int i = 1; i <= 3; i++) {
        if (ans[3] == ans[2] || ans[3] == ans[1] || ans[3] == ans[0]) {
            ans[3] = D[i].first;
        }
        else {
            break;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << ans[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    print();

    return 0;
}