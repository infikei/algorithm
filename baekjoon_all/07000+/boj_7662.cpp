// Solve 2022-08-30
// Update 2023-10-25

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
        priority_queue<int> pq_maxtop;
        priority_queue<int, vector<int>, greater<int> > pq_mintop;
        map<int, int> mp; // 저장한 수와 그 중복된 개수를 저장하는 map

        int k;
        cin >> k;

        for (int ki = 0; ki < k; ki++) {
            int n;
            char ch;
            cin >> ch >> n;

            if (ch == 'I') {
                pq_maxtop.push(n);
                pq_mintop.push(n);
                mp[n]++;
            }
            else {
                if (!mp.empty()) {
                    if (n == 1) {
                        while (!pq_maxtop.empty() && mp[pq_maxtop.top()] == 0) {
                            pq_maxtop.pop();
                        }

                        if (!pq_maxtop.empty()) {
                            mp[pq_maxtop.top()]--;
                            pq_maxtop.pop();
                        }
                    }
                    else {
                        while (!pq_mintop.empty() && mp[pq_mintop.top()] == 0) {
                            pq_mintop.pop();
                        }

                        if (!pq_mintop.empty()) {
                            mp[pq_mintop.top()]--;
                            pq_mintop.pop();
                        }
                    }
                }
            }
        }

        // 현재 저장되어있는 최댓값과 최솟값이 유효한지 검사한다.

        while (!pq_maxtop.empty() && mp[pq_maxtop.top()] == 0) {
            pq_maxtop.pop();
        }

        while (!pq_mintop.empty() && mp[pq_mintop.top()] == 0) {
            pq_mintop.pop();
        }

        // 결과 출력

        if (pq_mintop.empty() || pq_maxtop.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << pq_maxtop.top() << ' ' << pq_mintop.top() << '\n';
        }
    }

    return 0;
}
