#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> dic(n);
    map<string, int> str_map;
    for (int i = 0; i < n; ++i) {
        cin >> dic[i];
        sort(dic[i].begin(), dic[i].end());
        str_map[dic[i]]++;
    }

    cin >> n;
    vector<string> query(n);
    for (int i = 0; i < n; ++i) {
        cin >> query[i];
        sort(query[i].begin(), query[i].end());
        cout << str_map[query[i]] << '\n';
    }
    return 0;
}