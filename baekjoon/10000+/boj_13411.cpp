#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using pdi = pair<double, int>;

int N;
vector<pdi> time_and_idx;

int main() {
    fastio;

    cin >> N;

    int x, y, v;
    double t2;
    for (int i = 1; i <= N; i++) {
        cin >> x >> y >> v;
        t2 = (double)(x * x + y * y) / (v * v);
        time_and_idx.push_back(make_pair(t2, i));
    }

    sort(time_and_idx.begin(), time_and_idx.end());

    for (auto a : time_and_idx) {
        cout << a.second << '\n';
    }

    return 0;
}