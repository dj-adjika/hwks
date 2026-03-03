#include <iostream>
#include <string>

bool is_palindrome(std::string& s) {
    int len = s.length();

    int p1{ 0 };
    int p2{ len - 1 };

    while (p1 <= len / 2) {
        if (s[p1] == s[p2]) {
            p1++;
            p2--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    std::string& ref = s;
    std::cout << "Is a palindrome: " << is_palindrome(ref) <<std::endl;
}