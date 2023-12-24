// Solve 2023-12-24

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    int n, q;
    ll m;
    cin >> n >> m >> q;

    unordered_map<string, int> company_name_to_idx;
    vector<vector<int>> group_to_company(101, vector<int>());
    vector<int> company_price(n);
    vector<int> company_bought(n, 0);

    for (int i = 0; i < n; i++) {
        int group, price;
        string name;
        cin >> group >> name >> price;

        company_name_to_idx[name] = i;
        group_to_company[group].push_back(i);
        company_price[i] = price;
    }

    for (int i = 0; i < q; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            string name;
            ll buying;
            cin >> name >> buying;

            int idx = company_name_to_idx[name];
            ll buying_price = buying * company_price[idx];

            if (buying_price <= m) {
                m -= buying_price;
                company_bought[idx] += buying;
            }
        }
        else if (cmd == 2) {
            string name;
            int selling;
            cin >> name >> selling;

            int idx = company_name_to_idx[name];
            selling = min(company_bought[idx], selling);
            m += (ll)selling * company_price[idx];
            company_bought[idx] -= selling;
        }
        else if (cmd == 3) {
            string name;
            int changed_price;
            cin >> name >> changed_price;

            company_price[company_name_to_idx[name]] += changed_price;
        }
        else if (cmd == 4) {
            int group, changed_price;
            cin >> group >> changed_price;

            for (int &idx : group_to_company[group]) {
                company_price[idx] += changed_price;
            }
        }
        else if (cmd == 5) {
            int group, changed_price;
            cin >> group >> changed_price;

            changed_price += 100;

            for (int &idx : group_to_company[group]) {
                int new_price = company_price[idx] * (ll)changed_price / 100;
                company_price[idx] = new_price - new_price % 10;
            }
        }
        else if (cmd == 6) {
            cout << m << '\n';
        }
        else {
            ll new_m = m;

            for (int idx = 0; idx < n; idx++) {
                new_m += company_bought[idx] * (ll)company_price[idx];
            }

            cout << new_m << '\n';
        }
    }

    return 0;
}
