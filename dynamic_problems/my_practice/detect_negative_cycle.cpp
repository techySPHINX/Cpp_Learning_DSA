#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int INF = numeric_limits<int>::max(); // Use this to represent no edge

pair<bool, vector<vector<int>>> floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) { // Check for overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        if (dist[k][k] < 0) {
            return {true, {}};
        }
    }
    return {false, dist};
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter the adjacency matrix (use " << INF << " for no edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    auto result = floydWarshall(dist, n);
    bool hasNegativeCycle = result.first;
    vector<vector<int>> shortestPaths = result.second;

    if (hasNegativeCycle) {
        cout << "Negative weight cycle detected.\n";
    } else {
        cout << "The shortest distance matrix is:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (shortestPaths[i][j] == INF) {
                    cout << "INF "; // Print INF for no path
                } else {
                    cout << shortestPaths[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
