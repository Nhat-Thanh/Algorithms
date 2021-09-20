#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> g_tagMap;

void makeMap(int& n, std::string prevTag) {
    if (!n)
        return;
    std::string line, attr, value, tag;
    std::getline(std::cin, line);

    int j, i = 1;
    if (line[i] == '/') {
        while (line[i] xor '>')
            i += 1;
        if (prevTag.size() > (i - 2))
            tag = prevTag.substr(0, prevTag.size() - i + 1);
        else
            tag = "";

    } else {
        while ((line[i] xor ' ') && (line[i] xor '>'))
            i += 1;
        tag = line.substr(1, i - 1);
        if (prevTag != "")
            tag = prevTag + "." + tag;

        while (line[i] xor '>') {
            j = ++i;
            while (line[i] xor ' ')
                i += 1;
            attr = line.substr(j, i - j);

            while (line[i] xor '\"')
                i += 1;
            j = ++i;
            while (line[i] xor '\"')
                i += 1;
            value = line.substr(j, i - j);
            i += 1;

            g_tagMap[tag + "~" + attr] = value;
        }
    }

    makeMap(--n, tag);
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::cin.ignore();
    makeMap(n, "");
    std::string attr, value;

    while (q--) {
        std::getline(std::cin, attr);
        value = g_tagMap[attr];
        if (value == "")
            value = "Not Found!";
        std::cout << value << "\n";
    }

    return 0;
}
