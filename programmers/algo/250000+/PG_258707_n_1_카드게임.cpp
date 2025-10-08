// Solve 2025-10-08

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int solution(int coin, vector<int> cards) {
    int n = size(cards);
    vector<int> card_round(n / 2 + 1);
    vector<int> card_cost(n / 2 + 1);

    for (int i = n / 3, r = 1; i < n; i += 2, r++) {
        int v = cards[i] <= n / 2 ? cards[i] : (n + 1) - cards[i];
        card_round[v] = max(card_round[v], r);
        card_cost[v]++;

        v = cards[i + 1] <= n / 2 ? cards[i + 1] : (n + 1) - cards[i + 1];
        card_round[v] = max(card_round[v], r);
        card_cost[v]++;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq_by_round;
    priority_queue<pii, vector<pii>, greater<pii>> pq_by_cost;

    for (int v = 1; v <= n / 2; v++) {
        pq_by_round.emplace(card_round[v], card_cost[v]);
    }

    int round = 1;
    int max_round = n / 3 + 1;

    while (round < max_round) {
        while (!pq_by_round.empty() && pq_by_round.top().first <= round) {
            pii cur = pq_by_round.top();
            pq_by_round.pop();
            pq_by_cost.emplace(cur.second, cur.first);
        }

        if (pq_by_cost.empty() || pq_by_cost.top().first > coin) {
            break;
        }

        coin -= pq_by_cost.top().first;
        pq_by_cost.pop();
        round++;
    }

    return round;
}
