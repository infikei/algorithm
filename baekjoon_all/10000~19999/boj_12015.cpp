#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int N, arr[1000000], ans;
vector<int> v;

void solve() {
    v.push_back(arr[0]);
    ans = 1;

    for (int i = 1; i < N; i++) {
        if (v[ans - 1] < arr[i]) {
            v.push_back(arr[i]);
            ans++;
        }
        else {
            int low = 0, high = ans - 1, mid;
            int res = 10000000;
            while (low <= high) {
                mid = (low + high) / 2;

                if (arr[i] <= v[mid]) {
                    high = mid - 1;
                    res = min(res, mid);
                }
                else {
                    low = mid + 1;
                }
            }

            v[res] = arr[i];
        }
    }
}

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    cout << ans << '\n';

    return 0;
}