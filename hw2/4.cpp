#include <iostream>
#include <string>

// является ли строка исходной подстрокой для другой строки

bool isSubsequence(std::string& a, std::string& b){
    int i{0}, j{0};

    while (i < a.length() && j < b.length()){
        if (a[i] == b[i]){
            i++;
        }

        j++;
    }

    return i == a.length();
}

int main(){
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::string& ref1 = s1;
    std::string& ref2 = s2;

    std::cout << "Is Subsequence: " << isSubsequence(ref1, ref2) << std::endl;
}