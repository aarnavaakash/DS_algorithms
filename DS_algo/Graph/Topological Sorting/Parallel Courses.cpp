class Solution {
public:
    int topologicalSortBFS(unordered_map<int, vector<int>>& adj, int N, vector<int>& indegree) {
        queue<int> que;
        for(int i = 1; i<=N; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        int count  = 0;
        int result = 0;
        while(!que.empty()) {
            result++;
            int n = que.size();
            while(n--) {
                int curr = que.front();
                que.pop();
                count++;
                for(auto x:adj[curr]) {
                    indegree[x]--;
                    if(indegree[x] == 0) {
                        que.push(x);
                    }
                }
            }
        }
        return count==N?result:-1;
    }
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(N+1, 0);
        for(auto relation:relations) {
            int x = relation[0];
            int y = relation[1];
            adj[x].push_back(y);
            indegree[y]++;
        }

        return topologicalSortBFS(adj, N, indegree);
    }
};
