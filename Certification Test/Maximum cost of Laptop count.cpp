#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *cost = new int[n];
    int *dailyCount = new int[n];
    for (int i = 0; i < n; ++i) 
        cin >> cost[i];

    cin >> n;
    for (int i = 0; i < n; ++i){
        std::string str;
        cin >> str;
        dailyCount[i] = (str == "legal") ? 1 : 0;
    }

    int dc, s = 0, sum = 0, max = 0;
    cin >> dc;
    for (int i = 0; i < n; ++i) {
        s += dailyCount[i];
        sum += cost[i];
        if (s == dc) {
            max = (max < sum) ? sum : max;
            s = 0;
            sum = 0;
        }
    }
    cout << max;
    return 0;
}
