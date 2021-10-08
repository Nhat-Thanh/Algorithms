using namespace std;
#include <climits>
#include <iostream>
#include <string>
#include <vector>

int main() {
    string str, anagram;
    cin >> str >> anagram;

    int n = str.length();
    int m = anagram.length();

    vector<char> charmap(256);
    for (int i = 0; i < m; ++i)
        ++charmap[anagram[i]];

    for (int i = 0; i + m < n; ++i) {
        bool ok = true;
        vector<char> sub_charmap(charmap);
        for (int j = 0; j < m; ++j)
            ok = !((--sub_charmap[str[i + j]]) < 0) & ok;
        if (ok)
           cout << str.substr(i, m) << "\n";
    }

    return 0;
}
