// Solve 2023-04-27
// Update 2023-10-13

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;

int main() {
    FASTIO;

    string html;
    getline(cin, html);

    html = regex_replace(html, regex("</?main>"), "");
    html = regex_replace(html, regex("<div title=\"([a-zA-Z0-9_ ]*)\">"), "title : $1");
    html = regex_replace(html, regex("</div>"), "\n");
    html = regex_replace(html, regex("<p>"), "\n[");
    html = regex_replace(html, regex("</p>"), "]");
    html = regex_replace(html, regex("</?[a-z ]*>"), "");
    html = regex_replace(html, regex("\\[[ ]*([^\\[\\]]*)[ ]*\\]"), "[$1]");
    html = regex_replace(html, regex(" +"), " ");
    html = regex_replace(html, regex("\\[|\\]"), "");

    cout << html << '\n';

    return 0;
}
