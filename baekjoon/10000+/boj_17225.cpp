#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pii = pair<int, int>;
using vint = vector<int>;

int A, B, N;
priority_queue<pii, vector<pii>, greater<pii> > pq_min;
vint A_vec, B_vec;


int main() {
    fastio;

    cin >> A >> B >> N;

    int A_next = 0, B_next = 0;
    for (int i = 0; i < N; i++) {
        int t, m;
        char c;
        cin >> t >> c >> m;

        if (c == 'B') {
            A_next = max(t, A_next);
            for (int j = 0; j < m; j++) {
                pq_min.push(make_pair(A_next, 0));
                A_next += A;
            }
        }
        else {
            B_next = max(t, B_next);
            for (int j = 0; j < m; j++) {
                pq_min.push(make_pair(B_next, 1));
                B_next += B;
            }
        }
    }

    int idx = 1;
    while (!pq_min.empty()) {
        if (pq_min.top().second == 0) A_vec.push_back(idx);
        else B_vec.push_back(idx);
        idx++;
        pq_min.pop();
    }

    cout << (int)(A_vec.size()) << '\n';
    for (auto a : A_vec) {
        cout << a << ' ';
    }
    cout << '\n';
    cout << (int)(B_vec.size()) << '\n';
    for (auto a : B_vec) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}