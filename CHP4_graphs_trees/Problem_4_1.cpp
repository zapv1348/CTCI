// Problem 4.1
// given a directed graph, figure out if nodes are connected or not
// going from nodeA to nodeB

#include <vector>
#include <queue>

using namespace std;

class directedGraphNodes {
    // gonna do BFS here
    bool AreConnected(vector<vector<int>> graph, int nodeA, int nodeB) {
        queue<int> q;
        auto visited = vector<bool>(graph.size(), false);
        visited[nodeA] = true;
        q.push(nodeA);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto i : graph[node]) {
                if (i == nodeB) return true;
                if (visited[i] == false) {
                    q.push(i);
                    visited[i] == true;
                }
            }
        }
        
        return false;
    }
};
