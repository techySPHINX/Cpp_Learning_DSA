#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>

using namespace std;
using State = pair<int, int>;

struct StateHash {
    size_t operator()(const State& state) const {
        return hash<int>()(state.first) ^ hash<int>()(state.second);
    }
};

// TSP function using memoization
int tsp(const vector<vector<int>>& graph, int pos, int visited, unordered_map<State, int, StateHash>& memo) {
    if (visited == (1 << graph.size()) - 1) {
        return graph[pos][0]; 
    }
    State state = {pos, visited};
    if (memo.find(state) != memo.end()) {
        return memo[state];
    }

    int min_cost = INT_MAX;
    for (int city = 0; city < graph.size(); city++) {
        if (visited & (1 << city)) {
            continue;
        }
        int new_cost = graph[pos][city] + tsp(graph, city, visited | (1 << city), memo);
        min_cost = min(min_cost, new_cost);
    }

    memo[state] = min_cost;
    return min_cost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    unordered_map<State, int, StateHash> memo;
    int result = tsp(graph, 0, 1, memo);
    cout << "The minimum cost of the tour is: " << result << endl;
    return 0;
}
