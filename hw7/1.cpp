#include <iostream>
#include <vector>
#include <map>

// используем DFS для обхода дерева

bool dfsCycle(int v, int parent, std::map<int, bool>& visited, std::map<int, std::vector<int>>& graph) {
    visited[v] = true;

    for (int neighbor : graph[v]) {
        // Если сосед не является родителем — это потенциальный цикл
        if (neighbor != parent) {
            // Если сосед уже посещен, значит мы нашли обратное ребро (цикл)
            if (visited[neighbor] || dfsCycle(neighbor, v, visited, graph)) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(std::map<int, std::vector<int>>& graph) {
    std::map<int, bool> visited;
    for (auto const& [vertex, neighbors] : graph) {
        if (!visited[vertex]) {
            if (dfsCycle(vertex, -1, visited, graph)) {
                return true;
            }
        }
    }
    
    return false;
}