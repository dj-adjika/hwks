#include <iostream>
#include <string>
#include <vector>
#include <print>

// пусть открывающая скобка = 1
// закрывающая = -1

// здесь за O(1) по памяти(не используем вектор)

bool is_ok_brackets(const std::string& s){
    int balance{0};

    for (int i = 0; i<s.size();++i){
        if (s[i] == '('){
            ++balance;
        } else {
            --balance;
        }
        
        if(balance < 0){
            std::println("too many closing brackets");
            return false;
        }
    }

    if(balance!=0){
        std::println("Need to erase: {} brackets", balance);
        return false;
    }

    return true;
}

int main(){
    std::string tmp;

     while (std::cin >> tmp){
        std::println("{}", is_ok_brackets(tmp));
     }
}