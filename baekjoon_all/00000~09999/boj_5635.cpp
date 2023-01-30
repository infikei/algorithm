#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C++와 C 두 표준 입출력 동기화를 해제한다.
    cout.tie(NULL);
    cin.tie(NULL);                    // 입력과 출력이 묶여있는 것을 풀어준다.

    int N;
    cin >> N;

    vector<pair<int, string> > v;

    for (int i = 0; i < N; i++) {
        string name;
        int dd, mm, yyyy;

        cin >> name >> dd >> mm >> yyyy;

        int yyyymmdd = yyyy * 10000 + mm * 100 + dd;
        v.push_back(make_pair(yyyymmdd, name));
    }

    sort(v.begin(), v.end());

    cout << v[N - 1].second << '\n';
    cout << v[0].second << '\n';

    return 0;
}