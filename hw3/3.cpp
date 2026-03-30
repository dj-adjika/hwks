#include <iostream>
#include <vector>
#include <algorithm>

// сколько можно накормить животных, у которых потребность в еде <= количеству еды в массиве еды.

// подход с сортировкой будет наиболее оптимальным, так как после сортировку мы 
// можем линейно пройтись по обоим массивам, от min к max, чтобы не тратить большую порцию на 
// животного с маленькой потребностью 

int feed(std::vector<int>& animals, std::vector<int>& food){
    if (animals.size() == 0 || food.size() == 0) {
        return 0;
    }

    std::sort(animals.begin(), animals.end());
    std::sort(food.begin(), food.end());

    int cnt{0};

    for(const auto v: food){
        if (v >= animals[cnt]){
            cnt++;
        }

        if (cnt == animals.size()){
            break;
        }
    }

    return cnt;
}

int main(){
    std::vector animals{8, 2, 3, 2};
    std::vector food{1, 8, 4, 3};

    std::cout << "Total fed animals:" << feed(animals, food) << std::endl;
    return 0;
}