using namespace std;
#include <iostream>
#include <string>
#include <vector>

int main() {
    string str, anagram;
    cin >> str >> anagram;

    int n = str.length();
    int m = anagram.length();

    vector<char> charmap(256);
    for (int u = 0; u < n; ++u)
        ++charmap[str[u]];

    bool ok = true;
    vector<char> sub_charmap(charmap);
    for (int v = 0; v < m; ++v)
        if ((--sub_charmap[anagram[v]]) < 0)
            ok = false;

    cout << (ok ? "YES" : "NO") << "\n", 0;
    return 0;
}
