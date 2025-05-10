// Solve 2025-05-08

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

int dice[6];

int get_min_of_one_dice_side() {
    int res = dice[0];

    for (int i = 0; i < 6; i++) {
        res = min(res, dice[i]);
    }

    return res;
}

int get_min_sum_of_two_dice_sides() {
    int res = dice[0] + dice[1];

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) continue; // 2개의 면이 맞은 편에 있으면 탐색하지 않음

            res = min(res, dice[i] + dice[j]);
        }
    }

    return res;
}

int get_min_sum_of_three_dice_sides() {
    int res = dice[0] + dice[1] + dice[2];

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) continue; // 2개의 면이 맞은 편에 있으면 탐색하지 않음

            for (int k = j + 1; k < 6; k++) {
                if (i + k == 5 || j + k == 5) continue; // 3개의 면 중 맞은 편에 있는 2개의 면이 존재하면 탐색하지 않음

                res = min(res, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    return res;
}

int get_sum_of_dice() {
    int res = 0;

    for (int i = 0; i < 6; i++) {
        res += dice[i];
    }

    return res;
}

int main() {
    FASTIO;

    ll n;
    cin >> n;

    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    if (n == 1) {
        int sum_of_dice = get_sum_of_dice();
        int max_of_dice = *max_element(dice, dice + 6);
        int ans = sum_of_dice - max_of_dice;
        cout << ans << '\n';

        return 0;
    }

    int min_sum_of_some_dice_sides[4] = { 0 };
    min_sum_of_some_dice_sides[1] = get_min_of_one_dice_side();
    min_sum_of_some_dice_sides[2] = get_min_sum_of_two_dice_sides();
    min_sum_of_some_dice_sides[3] = get_min_sum_of_three_dice_sides();

    ll num_of_some_dice_sides[4] = { 0 }; // i번째 인덱스는 i개의 면만 보이는 주사위의 개수
    num_of_some_dice_sides[1] = (5 * n - 16) * n + 12;
    num_of_some_dice_sides[2] = 8 * n - 12;
    num_of_some_dice_sides[3] = 4;

    ll ans = 0;

    for (int i = 1; i <= 3; i++) {
        ans += min_sum_of_some_dice_sides[i] * num_of_some_dice_sides[i];
    }

    cout << ans << '\n';

    return 0;
}
