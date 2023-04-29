// Solve 2023-04-28

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

int arr[100001];
bool visited[100001];

int main() {
    FASTIO;

    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            visited[i] = false;
        }

        int ans = n;

        for (int i = 1; i <= n; i++) {
            if (arr[i] == 0) {
                continue;
            }

            stack<int> stck;
            int cur = i;

            while (true) {
                stck.push(cur);
                visited[cur] = true;

                cur = arr[cur];
                if (cur == 0) {
                    while (!stck.empty()) {
                        visited[stck.top()] = false;
                        arr[stck.top()] = 0;
                        stck.pop();
                    }
                    break;
                }
                if (visited[cur]) {
                    break;
                }
            }

            while (!stck.empty()) {
                int cur2 = stck.top();
                arr[cur2] = 0;
                visited[cur2] = false;
                stck.pop();
                ans--;

                if (cur2 == cur) {
                    while (!stck.empty()) {
                        visited[stck.top()] = false;
                        arr[stck.top()] = 0;
                        stck.pop();
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
