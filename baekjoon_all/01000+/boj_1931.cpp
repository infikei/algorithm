// Solve 2022-07-16
// Update 2024-02-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

struct Meeting{
    int begin, end;

    Meeting(int begin = 0, int end = 0) : begin(begin), end(end) {}

    bool operator<(const Meeting &rhs) const {
        if (end != rhs.end) return end < rhs.end;
        return begin < rhs.begin;
    }
};

Meeting meetings[100000];

int main() {
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int begin, end;
        cin >> begin >> end;
        meetings[i] = { begin, end };
    }

    sort(meetings, meetings + n);

    int max_count_of_meetings = 0;
    int end_of_last_meeting = 0;

    for (int i = 0; i < n; i++) {
        if (end_of_last_meeting <= meetings[i].begin) {
            max_count_of_meetings++;
            end_of_last_meeting = meetings[i].end;
        }
    }

    cout << max_count_of_meetings << '\n';

    return 0;
}
