#include <iostream>
#include <stack>
#define fastio ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL); // boj_15552.cpp
using namespace std;
using ll = long long;

int n;
ll ans;
stack<int> stck;

int main() {
    fastio;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int building;
        cin >> building;

        while (!stck.empty() && building >= stck.top()) {
            stck.pop();
        }
        ans += stck.size();
        stck.push(building);
    }

    cout << ans << '\n';

    return 0;
}