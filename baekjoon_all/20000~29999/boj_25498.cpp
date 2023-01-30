#include <iostream>
#include <string>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

const int N_MAX = 500000;
int n;
string s, ans;
vector<int> graph[N_MAX];
bool visited[N_MAX];

void bfs() {
    vector<int> vec_next;
    vec_next.push_back(0);
    visited[0] = true;

    while (!vec_next.empty()) {
        ans += s[vec_next[0]];

        vector<int> vec_now = vec_next;
        vec_next.clear();
        char next_char = 'a';

        while (!vec_now.empty()) {
            int now = vec_now.back();
            vec_now.pop_back();
            for (auto next : graph[now]) {
                if (!visited[next]) {
                    visited[next] = true;
                    if (s[next] > next_char) {
                        next_char = s[next];
                        vec_next.clear();
                        vec_next.push_back(next);
                    }
                    else if (s[next] == next_char) {
                        vec_next.push_back(next);
                    }
                }
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    bfs();

    cout << ans << '\n';

    return 0;
}