#include <vector>
#include <map>

// граф двудолен, если он допускает раскраску в два цвета так, что любые две 
// смежные вершины имеют разные цвета

bool dfsfunc(int v, int c, std::map<int, int>& colors, std::map<int, std::vector<int>>& graph) {
    colors[v] = c; // красим в цвет c (1 или -1)

    for (int neighbor : graph[v]) {
        if (colors[neighbor] == 0) {
            // соседа в противоположный цвет
            if (!dfsfunc(neighbor, -c, colors, graph)) return false;
        } else if (colors[neighbor] == colors[v]) {
            // конфликт цветов — сосед имеет тот же цвет
            return false;
        }
    }
    return true;
}

bool isBipartite(std::map<int, std::vector<int>>& graph) {
    std::map<int, int> colors; // 0 - не посещена, 1 - цвет 1, -1 - цвет 2
    for (auto const& [v, neighbors] : graph) {
        colors[v] = 0;
    }

    for (auto const& [v, neighbors] : graph) {
        if (colors[v] == 0) {
            if (!dfsfunc(v, 1, colors, graph)) {
                return false;
            }
        }
    }

    return true;
}