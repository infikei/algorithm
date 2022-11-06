#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N, M, ans;
vector<pii> house_list;
vector<pii> chicken_list;
vector<int> chicken_idx;

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
        int house_list_sz = house_list.size();
        int chicken_idx_sz = chicken_idx.size();
        vector<int> house_dist(house_list_sz);

        pii chicken = chicken_list[chicken_idx[0]];
        for (int j = 0; j < house_list_sz; j++) {
            pii house = house_list[j];
            house_dist[j] = abs(house.first - chicken.first) + abs(house.second - chicken.second);
        }

        for (int i = 1; i < chicken_idx_sz; i++) {
            pii chicken = chicken_list[chicken_idx[i]];
            for (int j = 0; j < house_list_sz; j++) {
                pii house = house_list[j];
                house_dist[j] = min(house_dist[j], abs(house.first - chicken.first) + abs(house.second - chicken.second));
            }
        }

        int result = 0;

        for (int i = 0; i < house_list_sz; i++) {
            result += house_dist[i];
        }

        ans = min(ans, result);
        return;
    }

    for (int i = a; i < (int)chicken_list.size(); i++) {
        chicken_idx.push_back(i);
        dfs(depth + 1, i + 1);
        chicken_idx.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    input();

    ans = 987654321;
    dfs();
    cout << ans << '\n';

    return 0;
}