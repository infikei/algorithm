// Solve 2025-06-02

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

int get_min_count_to_distinguish(vector<int>& file1, vector<int>& file2) {
    int min_len = min(file1.size(), file2.size());

    for (int i = 0; i < min_len; i++) {
        if (file1[i] != file2[i]) {
            return i + 1;
        }
    }

    return min_len + 1;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    vector<vector<int>> files;

    for (int i = 0; i < n; i++) {
        vector<int> file;
        int x;

        while (true) {
            cin >> x;

            if (x == -1) break;

            file.push_back(x);
        }

        files.push_back(file);
    }

    int max_min_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int min_cnt = get_min_count_to_distinguish(files[i], files[j]);
            max_min_cnt = max(max_min_cnt, min_cnt);
        }
    }

    cout << max_min_cnt << '\n';

    return 0;
}
