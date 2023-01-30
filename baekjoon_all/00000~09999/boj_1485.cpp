#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int d2(pii a, pii b) {
    int result = (a.first - b.first) * (a.first - b.first);
    result += (a.second - b.second) * (a.second - b.second);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int x, y;
        vector<pii> pt_vec;
        for (int i = 0; i < 4; i++) {
            cin >> x >> y;
            pt_vec.push_back(make_pair(x, y));
        }

        // 점 4개로 만들 수 있는 선분의 길이를 구한다.
        // 점 4개로 정사각형을 만들 수 있다면, 이 6개의 길이 중 4개가 같은 길이, 그리고 나머지 2개도 같은 길이여야 한다.
        vector<int> d2_vec;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                d2_vec.push_back(d2(pt_vec[i], pt_vec[j]));
            }
        }

        sort(d2_vec.begin(), d2_vec.end());

        if (d2_vec[0] == d2_vec[3] && d2_vec[4] == d2_vec[5]) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}