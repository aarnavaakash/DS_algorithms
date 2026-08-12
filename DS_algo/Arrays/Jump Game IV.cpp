class Solution {
public:
    int solve_BFS(vector<int>& arr, int& n) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> que;
        que.push(0);
        visited[0] = true;
        int steps = 0;

        while(!que.empty()) {
            int size = que.size();

            while(size--) {
                int curr = que.front();
                que.pop();

                if(curr == n-1) {

                    return steps;
                }

                int left  = curr-1;
                int right = curr+1;

                if(left >= 0 && !visited[left]) {
                    que.push(left);
                    visited[left] = true;
                }

                if(right < n && !visited[right]) {
                    que.push(right);
                    visited[right] = true;
                }

                for(const int &idx : mp[arr[curr]]) {
                    if(!visited[idx]) {
                        que.push(idx);
                        visited[idx] = true;
                    }
                }

                mp.erase(arr[curr]);
            }
            steps++;
        }

        return -1;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        return solve_BFS(arr, n);
    }
};

class Solution {
public:
    vector<bool> visited;
    vector<int> t;
    unordered_map<int, vector<int>> mp;
    int solve_DFS(vector<int>& arr, int idx) {

        if(idx == arr.size()-1)
            return 0;

        int min_step = INT_MAX;

        if (idx + 1 < arr.size() && !visited[idx+1]) {
            visited[idx+1] = true;
            min_step = min(min_step, solve_DFS(arr, idx+1) + 1);
            visited[idx+1] = false;
        }

        if (idx - 1 >= 0 && !visited[idx-1]) {
            visited[idx-1] = true;
            min_step = min(min_step, solve_DFS(arr, idx-1) + 1);
            visited[idx-1] = false;
        }

        for (int next_idx : mp[arr[idx]]) {
            if (next_idx == idx) {continue;}
            if (!visited[next_idx]) {
                visited[next_idx] = true;
                min_step = min(min_step, solve_DFS(arr, next_idx) + 1);
                visited[next_idx] = false;
            }
        }

        t[idx] = min(t[idx], min_step);
        return t[idx];
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        visited.resize(n);
        t.resize(n, INT_MAX);
        mp.clear();
        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        visited[0] = true;
        return solve_DFS(arr, 0);
    }
};
