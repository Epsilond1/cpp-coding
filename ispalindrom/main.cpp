#include <iostream>
#include <cstring>

bool isPalindrom(std::string& str) {
    if (str.empty()) {
        return false;
    }

    for (int start = 0, end = str.size() - 1; start < end; ++start, --end) {
        if (!isalnum(str[start])) {
            start++;
        }
        if (!isalnum(str[end])) {
            end--;
        }
        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << isPalindrom(str);
    return 0;
}