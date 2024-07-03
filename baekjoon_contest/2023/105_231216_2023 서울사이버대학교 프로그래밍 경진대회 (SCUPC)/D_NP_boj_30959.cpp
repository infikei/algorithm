// Solve 2023-12-18

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int predict_for_single(int m, vector<int> &model, vector<int> &answer) {
    int res = 0;

    for (int i = 0; i < m; i++) {
        if (model[i] == answer[i]) {
            res++;
        }
    }

    return res;
}

int predict_for_multiple(int n, int m, vector<vector<int>> &models, vector<int> &answer, vector<int> &selected_model_idxes, int depth = 0) {
    if (depth == n) {
        if (SIZE(selected_model_idxes) % 2 == 0) return 0;

        vector<int> new_model(m, 0);

        for (int i : selected_model_idxes) {
            for (int j = 0; j < m; j++) {
                new_model[j] += models[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            new_model[j] = min(1, new_model[j] * 2 / SIZE(selected_model_idxes));
        }

        return predict_for_single(m, new_model, answer);
    }

    int res1 = predict_for_multiple(n, m, models, answer, selected_model_idxes, depth + 1);

    selected_model_idxes.push_back(depth);
    int res2 = predict_for_multiple(n, m, models, answer, selected_model_idxes, depth + 1);
    selected_model_idxes.pop_back();

    return max(res1, res2);
}

int main() {
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<int> answer(m);

    for (int &x : answer) {
        cin >> x;
    }

    vector<vector<int>> models(n, vector<int>(m));

    for (vector<int> &model : models) {
        for (int &x : model) {
            cin >> x;
        }
    }

    int single_result = 0;

    for (vector<int> &model : models) {
        single_result = max(single_result, predict_for_single(m, model, answer));
    }

    vector<int> model_choices;
    int multiple_result = predict_for_multiple(n, m, models, answer, model_choices);

    cout << (multiple_result > single_result) << '\n';

    return 0;
}
