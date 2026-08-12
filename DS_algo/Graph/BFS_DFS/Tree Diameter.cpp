class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return findDiameter(n, adj);
    }

private:

    int findDiameter(int n, unordered_map<int, vector<int>>& adj) {

        auto [farthestNode, _] = findFarthestNode(n, adj, 0);

        auto [_, diameter] = findFarthestNode(n, adj, farthestNode);
        return diameter;
    }

    pair<int, int> findFarthestNode(int n, unordered_map<int, vector<int>>& adj, int sourceNode) {
        queue<int> que;
        vector<bool> visited(n, false);

        que.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0;
        int farthestNode = sourceNode;

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = que.front();
                que.pop();

                farthestNode = currentNode;

                for (int neighbor : adj[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        que.push(neighbor);
                    }
                }
            }
            if (!que.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};
