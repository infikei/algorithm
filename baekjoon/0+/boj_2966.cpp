#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using pis = pair<int, string>;

bool cmp(pis a, pis b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int N, cnt[3];
string answers;
string choose[3] = {"ABC", "BABC", "CCAABB"};
string name[3] = {"Adrian", "Bruno", "Goran"};
vector<pis> v;

int main() {
    fastio;

    cin >> N >> answers;

    for (int i = 0; i < N; i++) {
        char now = answers[i];
        if (now == choose[0][i % 3]) cnt[0]++;
        if (now == choose[1][i % 4]) cnt[1]++;
        if (now == choose[2][i % 6]) cnt[2]++;
    }

    for (int i = 0; i < 3; i++) {
        v.push_back(make_pair(cnt[i], name[i]));
    }
    sort(v.begin(), v.end(), cmp);

    cout << v[0].first << '\n';
    for (int i = 0; i < 3; i++) {
        if (v[i].first != v[0].first) break;
        cout << v[i].second << '\n';
    }

    return 0;
}