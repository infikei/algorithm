#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 100001;
int N;
vector<int> v[SIZE];
int parent[SIZE];
bool visited[SIZE];

void input() {
    cin >> N;

    for (int n = 0; n < N; n++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void dfs(int k = 1) {
    visited[k] = true;
    int child_sz = v[k].size();

    for (int i = 0; i < child_sz; i++) {
        int next_k = v[k][i];
        if (!visited[next_k]) {
            parent[next_k] = k;
            dfs(next_k);
        }
    }
}

void print() {
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    dfs();

    print();

    return 0;
}