#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using pii = pair<int, int>;

int N;
int score[4][4];
int criteria[4] = {0, 3, 2, 1};

bool cmp(pii a, pii b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void input_and_calc_sum() {
    cin >> N;
    for (int n = 0; n < N; n++) {
        for (int person = 1; person <= 3; person++) {
            int x;
            cin >> x;
            score[x][person]++;
        }
    }
    for (int person = 1; person <= 3; person++) {
        score[0][person] = score[1][person] + score[2][person] * 2 + score[3][person] * 3;
    }
}

vector<int> decide_person(vector<int> &v, int c = 0) {
    if (c > 3) {
        return v;
    }

    vector<pii> ranking;

    for (auto a : v) {
        ranking.push_back(make_pair(a, score[criteria[c]][a]));
    }

    sort(ranking.begin(), ranking.end(), cmp);

    vector<int> res;
    res.push_back(ranking[0].first);

    for (int i = 1; i < (int)ranking.size(); i++) {
        if (ranking[0].second == ranking[i].second) {
            res.push_back(ranking[i].first);
            continue;
        }
        break;
    }

    if ((int)res.size() == 1) {
        return res;
    }
    return decide_person(res, c + 1);
}

int main() {
    fastio;

    input_and_calc_sum();

    vector<int> vt = {1, 2, 3};
    vt = decide_person(vt);

    if ((int)vt.size() == 1) {
        cout << vt[0] << ' ' << score[0][vt[0]] << '\n';
    }
    else {
        cout << 0 << ' ' << score[0][vt[0]] << '\n';
    }

    return 0;
}