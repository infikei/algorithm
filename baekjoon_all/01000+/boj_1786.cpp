// Solve 2023-06-30
// Update 2024-03-29

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;


int main() {
    FASTIO;

    string t, p;
    getline(cin, t); // 본문
    getline(cin, p); // 패턴

    vector<int> pi(SIZE(p)); // 부분일치 테이블 배열
    int i = 1; // 본문 포인터
    int j = 0; // 패턴 포인터

    while (i < SIZE(p)) {
        if (p[i] == p[j]) {
            i++;
            j++;
            pi[i - 1] = j;
        }
        else {
            if (j > 0) {
                j = pi[j - 1];
            }
            else {
                i++;
            }
        }
    }

    i = 0; // 본문 포인터
    j = 0; // 패턴 포인터
    vector<int> indexes; // 등장 인덱스

    while (i < SIZE(t)) {
        if (t[i] == p[j]) {
            i++;
            j++;

            if (j == SIZE(p)) {
                indexes.push_back(i - SIZE(p) + 1);
                j = pi[j - 1];
            }
        }
        else {
            if (j > 0) {
                j = pi[j - 1];
            }
            else {
                i++;
            }
        }
    }

    cout << SIZE(indexes) << '\n';

    if (SIZE(indexes) > 0) {
        for (int idx : indexes) {
            cout << idx << ' ';
        }

        cout << '\n';
    }

    return 0;
}
