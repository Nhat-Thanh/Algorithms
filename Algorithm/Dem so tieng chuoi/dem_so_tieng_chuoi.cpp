#include <iostream>
#include <map>

int main() {
    std::string str;
    getline(std::cin, str);
    if (!str.length())
        return std::cout << "Chuoi rong.\n", 0;
    str += " ";

    std::map<std::string, int> num_of_words;
    for (int left = 0, right = 0; left < (int)str.length(); left = right) {
        right = left + 1;
        if (str[left] != ' ') {
            while (right < (int)str.length() && str[right] != ' ')
                ++right;
            ++num_of_words[str.substr(left, right - left)];
        }
    }

    for (int left = 0, right = 0; left < (int)str.length(); left = right) {
        right = left + 1;
        if (str[left] != ' ') {
            while (right < (int)str.length() && str[right] != ' ')
                ++right;

            std::string word;
            if (num_of_words[word = str.substr(left, right - left)]) {
                std::cout << word << ": " << num_of_words[word] << "\n";
                num_of_words[word] = 0;
            }
        }
    }

    return 0;
}
