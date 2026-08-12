class Solution {
public:
    void convert(TreeNode* current, int parent, unordered_map<int, vector<int>>& adj) {
        if (current == nullptr) {
            return;
        }

        if (parent != -1) {
            adj[current->val].push_back(parent);
        }

        if (current->left != nullptr) {
            adj[current->val].push_back(current->left->val);
        }
        if (current->right != nullptr) {
            adj[current->val].push_back(current->right->val);
        }
        convert(current->left, current->val, adj);
        convert(current->right, current->val, adj);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        convert(root, -1, adj);

        queue<int> que;
        que.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int minutes = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int curr = que.front();
                que.pop();

                for (int &ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
};

class Solution {
public:
    int result = INT_MIN;

    int solve(TreeNode* root, int start) {
        if(root == NULL) {
            return 0;
        }

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->val == start) {
            result = max(LH, RH);
            return -1;
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }

        return 0;
    }

    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);

        return result;
    }
};
