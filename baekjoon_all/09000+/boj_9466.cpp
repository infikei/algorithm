// Solve 2023-04-28
// Update 2023-12-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        vector<int> arr(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<bool> visited(n + 1, false);
        int ans = n;

        for (int i = 1; i <= n; i++) {
            if (arr[i] == -1) continue;

            vector<int> vec;
            int cur = i;

            while (true) {
                vec.push_back(cur);
                visited[cur] = true;
                cur = arr[cur];

                if (cur == -1) {
                    while (!vec.empty()) {
                        visited[vec.back()] = false;
                        arr[vec.back()] = -1;
                        vec.pop_back();
                    }

                    break;
                }

                if (visited[cur]) {
                    break;
                }
            }

            while (!vec.empty()) {
                int cur2 = vec.back();
                vec.pop_back();
                arr[cur2] = -1;
                visited[cur2] = false;
                ans--;

                if (cur2 == cur) {
                    while (!vec.empty()) {
                        visited[vec.back()] = false;
                        arr[vec.back()] = -1;
                        vec.pop_back();
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
