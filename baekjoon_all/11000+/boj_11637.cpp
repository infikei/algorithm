// Solve 2025-04-20

#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define SETW(n, c) cout << setw(n) << setfill(c);
#define SETP(n) cout << fixed << setprecision(n);

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

string get_result_of_votes(vector<int> &votes) {
    int n = votes.size();
    int votes_sum = 0;

    for (int &v : votes) {
        votes_sum += v;
    }

    int max_vote = -1;
    int idx_of_max_vote = -1;

    for (int i = 0; i < n; i++) {
        if (votes[i] > votes_sum / 2) {
            return "majority winner " + to_string(i + 1);
        }

        if (votes[i] > max_vote) {
            max_vote = votes[i];
            idx_of_max_vote = i;
        }
        else if (votes[i] == max_vote) {
            idx_of_max_vote = -1;
        }
    }

    if (idx_of_max_vote == -1) {
        return "no winner";
    }

    return "minority winner " + to_string(idx_of_max_vote + 1);
}

int main() {
    FASTIO;

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> votes(n);

        for (int &v : votes) {
            cin >> v;
        }

        cout << get_result_of_votes(votes) << '\n';
    }

    return 0;
}
