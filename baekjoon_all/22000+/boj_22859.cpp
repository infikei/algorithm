// Solve 2023-04-27

#include <bits/stdc++.h>
using namespace std;

#ifdef BOJ
#define BOJTEST(x) ((void)0)
#else
#define BOJTEST(x) cout << "[Debug] " << #x << ':' << x << '\n'
#endif
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); // boj_15552.cpp
#define SETPRECISION(n) cout << fixed;cout.precision(n); // boj_1008.cpp
#define SIZE(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

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
