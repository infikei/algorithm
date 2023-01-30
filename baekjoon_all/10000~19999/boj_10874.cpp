#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;

int main() {
    fastio;

    int exam_ans[10];
    for (int i = 0; i < 5; i++) {
        exam_ans[i] = exam_ans[i + 5] = i + 1;
    }

    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        int x, cnt = 0;
        for (int i = 0; i < 10; i++) {
            cin >> x;
            if (x == exam_ans[i]) cnt++;
        }

        if (cnt == 10) cout << k << '\n';
    }

    return 0;
}