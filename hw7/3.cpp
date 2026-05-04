#include <vector>
#include <queue>
#include <map>

/*
    Алгоритм Дейкстры. Использование приоритетной очереди позволяет каждый раз выбирать
    вершину с минимальным текущим расстоянием 
    Каждое ребро E обрабатывается один раз и может происходить вставка/удаление в
    очередь - log(V) => сложность: O((E+V)log(V))
*/

using namespace std;

constexpr int INF = 1e9;

map<int, int> dijkstra(map<int, vector<pair<int, int>>>& graph, int start) {
    map<int, int> distances;
    for (auto const& [v, neighbors] : graph) {
        distances[v] = INF;
    }
    
    distances[start] = 0;
    // pair<расстояние, вершина>, min-priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;

        pq.pop();

        if (d > distances[v]) {
            continue;
        }

        for (auto& edge : graph[v]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distances[v] + weight < distances[neighbor]) {
                distances[neighbor] = distances[v] + weight;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }

    return distances;
}