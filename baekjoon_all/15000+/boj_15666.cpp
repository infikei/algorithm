#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, v_size, ans[8];
vector<int> v;

void input() {
    cin >> N >> M;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    v_size = v.size();
}

void dfs(int depth = 0, int begin = 0) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = begin; i < v_size; i++) {
        ans[depth] = v[i];
        dfs(depth + 1, i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    dfs();

    return 0;
}