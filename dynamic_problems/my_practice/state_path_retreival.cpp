#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {
public:
    Graph(int n) : n(n) {
        adjList.resize(n);
    }

    void addEdge(int start, int end, int weight) {
        adjList[start].emplace_back(end, weight);
    }

    pair<int, list<int>> dijkstra(int start, int target) {
        vector<int> dist(n, numeric_limits<int>::max());
        vector<int> prev(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currDist > dist[u]) continue;

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return retrievePath(dist, prev, target);
    }
    pair<int, list<int>> retrievePath(const vector<int>& dist, const vector<int>& prev, int target) {
        list<int> path;
        for (int at = target; at != -1; at = prev[at]) {
            path.push_front(at);
        }

        if (dist[target] == numeric_limits<int>::max()) {
            return { -1, {} }; // No path found
        }

        return { dist[target], path };
    }

private:
    int n;
    vector<vector<pair<int, int>>> adjList; 
};

int main() {
    int n; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    Graph graph(n);

    int edgesCount;
    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    cout << "Enter edges in the format (start end weight):\n";
    for (int i = 0; i < edgesCount; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph.addEdge(start, end, weight);
    }

    int startVertex, targetVertex;
    cout << "Enter the start vertex and target vertex: ";
    cin >> startVertex >> targetVertex;

    auto result = graph.dijkstra(startVertex, targetVertex);
    int minCost = result.first;
    list<int> path = result.second;

    if (minCost == -1) {
        cout << "No path found from " << startVertex << " to " << targetVertex << ".\n";
    } else {
        cout << "Minimum cost: " << minCost << "\nPath: ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
