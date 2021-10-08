#include <iostream>
#include <string>
#include <algorithm>

bool valid(const std::string& s,
           const std::string& t,
           int k) {
    if (s.size() + t.size() < k)
        return true;
    
    int i = 0;
    while (i < s.size() && s[i] == t[i])
        i++;
    k = (k - int(s.size()) - int(t.size()) + 2 * i);
    if (k >= 0 && k % 2 == 0)
        return true;

    return false;
}

int main() {
    std::string s, t;
    std::cin >> s;
    std::cin >> t;

    int k;
    std::cin >> k;
    std::cout << s.size() << '\n';
    std::cout << t.size() << '\n';

    // int i = 0;
    // while (i < s.size() && s[i] == t[i])
    //     i++;

    // k -= s.size() - i;
    // std::cout << ((k - int(t.size()) + i == 0) ? "Yes" : "No");
    std::cout << (valid(s, t, k) ? "Yes\n" : "No\n");
    return 0;
}