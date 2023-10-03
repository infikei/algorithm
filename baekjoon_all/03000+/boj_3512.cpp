// Solve 2023-10-03

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    SETPRECISION(1);

    int n, cost;
    cin >> n >> cost;

    int all_rooms_area = 0;
    int bedroom_area = 0;
    int balcony_area = 0;

    for (int i = 0; i < n; i++) {
        int room_area;
        string room_type;
        cin >> room_area >> room_type;

        all_rooms_area += room_area;

        if (room_type == "bedroom") {
            bedroom_area += room_area;
        }
        else if (room_type == "balcony") {
            balcony_area += room_area;
        }
    }

    cout << all_rooms_area << '\n';
    cout << bedroom_area << '\n';
    cout << (all_rooms_area - balcony_area * 0.5) * cost << '\n';

    return 0;
}
