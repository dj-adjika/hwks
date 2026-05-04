#include <queue>
#include <set>
#include <vector>
#include <map>

// дерево - связный граф без циклов, соответственно, нужно проверить эти два аспекта
// отсутствие циклов проверяется аналогично задаче 1, связность (доступность любой
// вершины из родителя) проверяется через BFS

bool isTree(std::map<int, std::vector<int>>& graph, int start) {
    if (graph.empty()) {
        return true;
    }

    std::set<int> visited;
    std::queue<int> q;
    std::map<int, int> parent;

    q.push(start);
    parent[start] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visited.insert(v);

        for (int neighbor : graph[v]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                parent[neighbor] = v;
            } else {
                // если сосед посещен и не является родителем — есть цикл
                if (parent[v] != neighbor) {
                    return false;
                }
            }
        }
    }
    // дерево должно быть связным (все вершины посещены)
    return visited.size() == graph.size();
}