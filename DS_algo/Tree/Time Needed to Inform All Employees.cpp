class Solution {
public:

    int maxTime = INT_MIN;

    void DFS(unordered_map<int, vector<int>> &adj, vector<int>& informTime, int curr_employee, int curr_time) {
        maxTime = max(maxTime, curr_time);

        for(int &v : adj[curr_employee]) {

            DFS(adj, informTime, v, curr_time + informTime[curr_employee]);

        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < manager.size(); i++) {
            int child     = i;
            int manager_i = manager[i];

            if(manager_i != -1)
                adj[manager_i].push_back(child);
        }

        DFS(adj, informTime, headID, 0);
        return maxTime;
    }
};

class Solution {
public:

    int maxTime = INT_MIN;

    void BFS(unordered_map<int, vector<int>> &adj, vector<int>& informTime, int headID) {

        queue<pair<int, int>> que;

        que.push({headID, 0});

        while(!que.empty()) {

            pair<int, int> temp = que.front();
            int curr_emp  = temp.first;
            int curr_time = temp.second;

            maxTime = max(maxTime, curr_time);

            que.pop();

            for(int &v : adj[curr_emp]) {
                que.push({v, curr_time + informTime[curr_emp]});
            }

        }

    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < manager.size(); i++) {
            int child     = i;
            int manager_i = manager[i];

            if(manager_i != -1)
                adj[manager_i].push_back(child);
        }

        BFS(adj, informTime, headID);
        return maxTime;
    }
};
