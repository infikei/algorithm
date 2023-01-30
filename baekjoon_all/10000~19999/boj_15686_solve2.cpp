#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N, M, ans;
vector<pii> house_list;
vector<pii> chicken_list;
vector<int> chicken_idx;
vector<vector<int> > dist;

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                house_list.push_back(make_pair(i, j));
            }
            else if (x == 2) {
                chicken_list.push_back(make_pair(i, j));
            }
        }
    }
}

void dfs(int depth = 0, int a = 0) {
    if (depth == M) {
        int res = 0;

        for (int col = 0; col < house_list.size(); col++) {
            int tmp = dist[chicken_idx[0]][col];
            for (int row = 1; row < M; row++) {
                tmp = min(tmp, dist[chicken_idx[row]][col]);
            }
            res += tmp;
        }

        ans = min(ans, res);
        return;
    }

    for (int i = a; i < (int)chicken_list.size(); i++) {
        chicken_idx.push_back(i);
        dfs(depth + 1, i + 1);
        chicken_idx.pop_back();
    }
}

void solve() {
    int house_list_sz = house_list.size();
    int chicken_list_sz = chicken_list.size();

    for (int i = 0; i < chicken_list_sz; i++) {
        vector<int> tmp;
        for (int j = 0; j < house_list_sz; j++) {
            tmp.push_back(abs(house_list[j].first - chicken_list[i].first) + abs(house_list[j].second - chicken_list[i].second));
        }
        dist.push_back(tmp);
    }

    ans = 987654321;
    dfs();
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    solve();

    cout << ans << '\n';

    return 0;
}