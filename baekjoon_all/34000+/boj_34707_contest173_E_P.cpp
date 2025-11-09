// Solve 2025-11-08

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int arr[500001];
bool visited[500001];

int main() {
    FASTIO;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    priority_queue<int> pq_maxtop;
    priority_queue<int, vector<int>, greater<int>> pq_mintop;

    for (int i = 1; i < k; i++) {
        visited[arr[i]] = true;
        pq_maxtop.push(arr[i]);
        pq_mintop.push(arr[i]);
    }

    for (int i = k; i <= n; i++) {
        visited[arr[i]] = true;
        pq_maxtop.push(arr[i]);
        pq_mintop.push(arr[i]);

        if (pq_maxtop.top() - pq_mintop.top() == k - 1) {
            cout << "YES" << '\n';

            for (int j = i - k + 1; j <= i; j++) {
                cout << arr[j] << ' ';
            }

            cout << '\n';
            return 0;
        }

        visited[arr[i - k + 1]] = false;

        while (!pq_maxtop.empty() && !visited[pq_maxtop.top()]) {
            pq_maxtop.pop();
        }

        while (!pq_mintop.empty() && !visited[pq_mintop.top()]) {
            pq_mintop.pop();
        }
    }

    cout << "NO" << '\n';
    return 0;
}
