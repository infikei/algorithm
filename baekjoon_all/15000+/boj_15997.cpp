// Solve 2026-02-03

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end());
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

string country_name[5];
unordered_map<string, int> country_idx;
int a[6], b[6];
double w[6], d[6], l[6];
int score[5];
double prob_next_round[5];

void recur(int dep, double prob) {
    if (dep == 6) {
        vector<pii> vec;

        for (int i = 1; i <= 4; i++) {
            vec.emplace_back(score[i], i);
        }

        sort(vec.begin(), vec.end(), greater<pii>());

        if (vec[1].first > vec[2].first) {
            prob_next_round[vec[0].second] += prob;
            prob_next_round[vec[1].second] += prob;
            return;
        }

        if (vec[0].first > vec[1].first) {
            prob_next_round[vec[0].second] += prob;

            if (vec[2].first > vec[3].first) {
                prob_next_round[vec[1].second] += prob / 2;
                prob_next_round[vec[2].second] += prob / 2;
            }
            else {
                prob_next_round[vec[1].second] += prob / 3;
                prob_next_round[vec[2].second] += prob / 3;
                prob_next_round[vec[3].second] += prob / 3;
            }

            return;
        }

        if (vec[2].first > vec[3].first) {
            prob_next_round[vec[0].second] += prob * 2 / 3;
            prob_next_round[vec[1].second] += prob * 2 / 3;
            prob_next_round[vec[2].second] += prob * 2 / 3;
        }
        else {
            prob_next_round[vec[0].second] += prob / 2;
            prob_next_round[vec[1].second] += prob / 2;
            prob_next_round[vec[2].second] += prob / 2;
            prob_next_round[vec[3].second] += prob / 2;
        }

        return;
    }

    score[a[dep]] += 3;
    recur(dep + 1, prob * w[dep]);
    score[a[dep]] -= 3;

    score[a[dep]] += 1;
    score[b[dep]] += 1;
    recur(dep + 1, prob * d[dep]);
    score[b[dep]] -= 1;
    score[a[dep]] -= 1;

    score[b[dep]] += 3;
    recur(dep + 1, prob * l[dep]);
    score[b[dep]] -= 3;
}

int main() {
    FASTIO;

    for (int i = 1; i <= 4; i++) {
        string s;
        cin >> s;
        country_name[i] = s;
        country_idx[s] = i;
    }

    for (int i = 0; i < 6; i++) {
        string name1, name2;
        cin >> name1 >> name2 >> w[i] >> d[i] >> l[i];
        a[i] = country_idx[name1];
        b[i] = country_idx[name2];
    }

    recur(0, 1);

    SETP(10);

    for (int i = 1; i <= 4; i++) {
        cout << prob_next_round[i] << '\n';
    }

    return 0;
}
