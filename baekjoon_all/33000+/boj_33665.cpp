// Solve 2025-09-09

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

int w[10][5];
int a, b;

int calculate_value(int player_num, vector<int>& money, string& city_owner, string& city_dambo) {
    int ret = 0;

    for (int i = 0; i < 10; i++) {
        int cnt = 0;

        for (int j = 0; j < 4; j++) {
            if (city_owner[i * 4 + j] == ('0' + player_num)) {
                cnt++;

                if (city_dambo[i * 4 + j] == '1') {
                    ret -= b;
                }
            }
        }

        ret += w[i][cnt];
    }

    ret += money[player_num] * a / 100;
    return ret;
}

int main() {
    FASTIO;

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> w[i][j];
        }
    }

    string city_owner, city_trade, city_dambo;
    cin >> city_owner >> city_trade >> city_dambo;
    vector<int> money(3), money_trade(3);
    cin >> money[1] >> money[2];
    cin >> money_trade[1] >> money_trade[2];
    cin >> a >> b;

    int before_trade = calculate_value(1, money, city_owner, city_dambo);
    before_trade -= calculate_value(2, money, city_owner, city_dambo);

    for (int i = 0; i < 40; i++) {
        if (city_trade[i] == '1') {
            city_owner[i] = '1';
        }
        else if (city_trade[i] == '2') {
            city_owner[i] = '2';
        }
    }

    money[1] += money_trade[2] - money_trade[1];
    money[2] += money_trade[1] - money_trade[2];

    int after_trade = calculate_value(1, money, city_owner, city_dambo);
    after_trade -= calculate_value(2, money, city_owner, city_dambo);

    cout << (after_trade >= before_trade ? "YES" : "NO") << '\n';
    return 0;
}
