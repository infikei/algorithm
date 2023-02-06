#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int n;
bool visited[9];
vector<int> buffer;

void dfs(int depth = 0) {
    if (depth == n) {
        for (auto a : buffer) cout << a << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        buffer.push_back(i);
        dfs(depth + 1);
        buffer.pop_back();
        visited[i] = false;
    }
}

int main() {
    fastio;

    cin >> n;

    dfs();

    return 0;
}