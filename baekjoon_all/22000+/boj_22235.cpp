// Solve 2022-08-20
// Update 2023-09-11

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    // 수인분당선 청량리역(K210)에서 인천역(K272)까지 걸리는 시간을 누적 합으로 저장한다.
    // 이때 각 역의 출발시각을 기준으로 하여 그 사이 시간을 저장할 것이므로 출발역 출발시각~도착역 도착시각 사이의 시간은 20초를 빼주어야 한다.

    int suin_bundang_time[73] = { 0 };

    suin_bundang_time[11] = 60;
    suin_bundang_time[21] = 120;
    suin_bundang_time[22] = 120;
    suin_bundang_time[23] = 60;
    suin_bundang_time[26] = 60;
    suin_bundang_time[39] = 60;
    suin_bundang_time[46] = 120;
    suin_bundang_time[48] = 180;
    suin_bundang_time[50] = 120;
    suin_bundang_time[51] = 60;
    suin_bundang_time[57] = 60;
    suin_bundang_time[67] = 60;

    for (int i = 10; i <= 72; i++) {
        suin_bundang_time[i] += suin_bundang_time[i - 1] + 140;
    }

    // 여기서부터 구현 시작

    string cur_str;
    int n;
    cin >> cur_str >> n;

    int pos = 25, cur = 0;
    stringstream ss(cur_str);
    string w;
    getline(ss, w, ':'); cur += stoi(w) * 3600;
    getline(ss, w, ':'); cur += stoi(w) * 60;
    getline(ss, w, ':'); cur += stoi(w);

    for (int i = 0; i < n; i++) {
        string from_str, to_str, when_str;
        cin >> from_str >> to_str >> when_str;

        int from = stoi(from_str.substr(2, 2));
        int to = stoi(to_str.substr(2, 2));

        if (to < pos || pos < from) continue;

        int when = 0;
        stringstream ss(when_str);
        string w;
        getline(ss, w, ':'); when += stoi(w) * 3600;
        getline(ss, w, ':'); when += stoi(w) * 60;

        when += suin_bundang_time[pos] - suin_bundang_time[from];

        if (when < cur) continue;

        when += suin_bundang_time[to] - suin_bundang_time[pos] - 20;
        cur = when;
        pos = to;

        if (cur >= 86400 || pos == 72) break;
    }

    if (pos != 72 || cur >= 86400) {
        cout << -1 << '\n';
    }
    else {
        int ans_hour = cur / 3600;
        int ans_min = cur / 60 % 60;
        int ans_sec = cur % 60;

        cout << setfill('0') << setw(2) << ans_hour << ':';
        cout << setfill('0') << setw(2) << ans_min << ':';
        cout << setfill('0') << setw(2) << ans_sec << '\n';
    }

    return 0;
}
