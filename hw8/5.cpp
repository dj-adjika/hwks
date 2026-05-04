#include <iostream>
#include <string>
#include <vector>
#include <print>

// пусть открывающая скобка = 1
// закрывающая = -1

bool is_ok_brackets(const std::string& s){
    std::vector<int> vec;
    vec.resize(s.size());

    if ((s[0] == ')' || s[0] == '(') &&s.size() == 1){
        return false;
    }
    
    if (s[0] == '('){
        vec[0] = 1;
    } else {
        vec[0] = -1;
    }

    for (int i = 1; i<s.size();++i){
        if (vec[i-1] < 0){
            return false;
        }
        
        if (s[i] == '('){
            vec[i] = vec[i-1] + 1;
        } else {
            vec[i] = vec[i-1] - 1;

            if (vec[i] < 0){
                return false; // получили, что закрывающих скобок больше открывающих
                // на каком-то этапе
            }
        }
    }

    if (vec.back()!=0){
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