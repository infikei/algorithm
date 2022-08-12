#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tiii;

int N, ans[200001];
vector<tiii> v;

bool cmp(const tiii &a, const tiii &b) {
    return get<2>(a) < get<2>(b);
}

bool cmp2(const tiii &a, const tiii &b) {
    if (get<1>(a) == get<1>(b)) {
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) < get<1>(b);
}

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    cin >> N;
    int c, s;
    for (int i = 1; i <= N; i++) {
        cin >> c >> s;
        v.push_back(make_tuple(i, c, s));
    }

    sort(v.begin(), v.end(), cmp);

    int sum = 0, duplicated = 0;
    for (int i = 0; i < N; i++) {
        int now_size = get<2>(v[i]);

        if (i > 0 && now_size == get<2>(v[i - 1])) {
            duplicated++;
        }
        else {
            duplicated = 0;
        }

        ans[get<0>(v[i])] = sum - duplicated * now_size;
        sum += now_size;
    }

    sort(v.begin(), v.end(), cmp2);

    sum = 0, duplicated = 0;
    for (int i = 0; i < N; i++) {
        int now_color = get<1>(v[i]);
        int now_size = get<2>(v[i]);

        if (i > 0 && now_color != get<1>(v[i - 1])) {
            sum = 0;
            duplicated = 0;
        }
        else {
            if (i > 0 && now_size == get<2>(v[i - 1])) {
                duplicated++;
            }
            else {
                duplicated = 0;
            }
        }

        ans[get<0>(v[i])] -= sum - duplicated * now_size;
        sum += now_size;
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}