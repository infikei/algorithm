#include <iostream>
#include <vector>
#include <stack>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vint = vector<int>;

int N;
ll ans;
vint vec;
stack<pii> stck;

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int now = vec[i];
        while (!stck.empty() && stck.top().first < now) {
            ans += (ll)(stck.top().second);
            stck.pop();
        }
        if (stck.empty()) {
            stck.push(make_pair(now, 1));
        }
        else if (stck.top().first == now) {
            pii now_pair = stck.top();
            stck.pop();
            if (!stck.empty()) ans++;
            ans += (ll)(now_pair.second);
            now_pair.second++;
            stck.push(now_pair);
        }
        else {
            if (!stck.empty()) ans++;
            stck.push(make_pair(now, 1));
        }
    }

    cout << ans << '\n';

    return 0;
}