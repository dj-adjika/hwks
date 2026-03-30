#include <iostream>
#include <string>
#include <map>

// найти символ, который есть во второй строке, но нет в первой, с учётом перемешивания

// Сложность O(n), так как мы линейно проходим 3 раза по строкам, 
// а операции с map имеют сложность O(1)

char find_sym(std::string& s1, std::string& s2) {
    std::map<char, int> m2{};

    for (int i{ 0 };i < s2.size();i++) {
        m2[s2[i]]++;
    }

    for (int i{ 0 };i < s1.size();i++) {
        if (m2.contains(s1[i])) { 
            // обнуляем счётчик для символов, присутсвующих в первой строке
            m2[s1[i]]--;
        }
    }

    for (const auto& [key, value] : m2) {
        if (value > 0) {
            return key; // оставшийся символ с ненулевым счётчиком - искомый
        }
    }

    return ' ';
}

int main() {
    std::string s1, s2; 
    std::cin >> s1 >> s2; 

    std::cout << find_sym(s1, s2) << std::endl;
}