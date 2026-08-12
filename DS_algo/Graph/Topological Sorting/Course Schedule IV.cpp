class Solution {
public:

    bool dfs(unordered_map<int, vector<int>>& adj, int src, int dest, vector<bool>& visited) {
        visited[src] = true;

        if(src == dest) {
            return true;
        }

        bool isReacheable = false;
        for(auto &adjNode : adj[src]) {
            if(!visited[adjNode]) {
                isReacheable = isReacheable || dfs(adj, adjNode, dest, visited);
            }
        }

        return isReacheable;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> visited(numCourses, false);
            result[i] = dfs(adj, u, v, visited);
        }

        return result;
    }
};

class Solution {
public:

    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, int src, int target) {
        visited[src] = true;

        if (src == target) {
            return true;
        }

        bool isPrerequisite = false;
        for (auto adjNode : adj[src]) {
            if (!visited[adjNode]) {
                isPrerequisite = isPrerequisite || dfs(adj, visited, adjNode, target);
            }
        }
        return isPrerequisite;
    }

    void preprocess(int numCourses, unordered_map<int, vector<int>>& adjList, vector<vector<bool>>& isPrerequisite) {
        for (int u = 0; u < numCourses; u++) {
            for (int v = 0; v < numCourses; v++) {
                if (u != v) {
                    vector<bool> visited(numCourses, false);
                    if (dfs(adjList, visited, u, v)) {
                        isPrerequisite[u][v] = true;
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        preprocess(numCourses, adjList, isPrerequisite);

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            result[i] = isPrerequisite[u][v];
        }

        return result;
    }
};

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                que.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> mp;
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (auto &ngbr : adj[node]) {

                mp[ngbr].insert(node);
                for (auto &prereq : mp[node]) {
                    mp[ngbr].insert(prereq);
                }

                indegree[ngbr]--;
                if (!indegree[ngbr]) {
                    que.push(ngbr);
                }
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);
        for (int i = 0; i < Q; i++) {
            int src  = queries[i][0];
            int dest = queries[i][1];

            bool isReachable = mp[dest].contains(src);
            result[i] = isReachable;
        }

        return result;
    }
};
