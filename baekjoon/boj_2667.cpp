#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt;
string graph[25];
bool visited[25][25];
vector<int> ans;

void input() {
    cin >> N;

    for (int row = 0; row < N; row++) {
        cin >> graph[row];
    }
}

int dfs(int r, int c) {
    int res = 1;
    visited[r][c] = true;

    if (r > 0 && !visited[r - 1][c] && graph[r - 1][c] == '1') {
        res += dfs(r - 1, c);
    }
    if (r < (N - 1) && !visited[r + 1][c] && graph[r + 1][c] == '1') {
        res += dfs(r + 1, c);
    }
    if (c > 0 && !visited[r][c - 1] && graph[r][c - 1] == '1') {
        res += dfs(r, c - 1);
    }
    if (c < (N - 1) && !visited[r][c + 1] && graph[r][c + 1] == '1') {
        res += dfs(r, c + 1);
    }

    return res;
}

void solve() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (graph[row][col] == '1' && !visited[row][col]) {
                cnt++;
                ans.push_back(dfs(row, col));
            }
        }
    }
}

void print() {
    cout << cnt << '\n';

    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    print();

    return 0;
}