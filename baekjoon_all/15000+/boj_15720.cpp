// Solve 2025-04-21

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

int main() {
    FASTIO;

    int b, c, d;
    cin >> b >> c >> d;

    vector<int> burgers(b);
    vector<int> sidemenus(c);
    vector<int> drinks(d);

    for (int &x : burgers) cin >> x;
    for (int &x : sidemenus) cin >> x;
    for (int &x : drinks) cin >> x;

    sort(burgers.begin(), burgers.end(), greater<int>());
    sort(sidemenus.begin(), sidemenus.end(), greater<int>());
    sort(drinks.begin(), drinks.end(), greater<int>());

    int min_bcd = min(b, min(c, d));
    int price_sum = 0;

    for (int i = 0; i < min_bcd; i++) {
        price_sum += burgers[i] + sidemenus[i] + drinks[i];
    }

    int sale_price_sum = price_sum / 10 * 9;
    int other_price_sum = 0;

    for (int i = min_bcd; i < b; i++) other_price_sum += burgers[i];
    for (int i = min_bcd; i < c; i++) other_price_sum += sidemenus[i];
    for (int i = min_bcd; i < d; i++) other_price_sum += drinks[i];

    price_sum += other_price_sum;
    sale_price_sum += other_price_sum;

    cout << price_sum << '\n';
    cout << sale_price_sum << '\n';

    return 0;
}
