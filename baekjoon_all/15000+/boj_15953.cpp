#include <iostream>
#include <vector>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using pii = pair<int, int>;

pii A[7] = {{0, 0}, {1, 500}, {3, 300}, {6, 200}, {10, 50}, {15, 30}, {21, 10}};
pii B[6] = {{0, 0}, {1, 512}, {3, 256}, {7, 128}, {15, 64}, {31, 32}};

int main() {
    fastio;

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int a, b;
        cin >> a >> b;

        int ans = 0;
        for (int i = 0; i < 7; i++) {
            if (a <= A[i].first) {
                ans += A[i].second * 10000;
                break;
            }
        }
        for (int i = 0; i < 6; i++) {
            if (b <= B[i].first) {
                ans += B[i].second * 10000;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}