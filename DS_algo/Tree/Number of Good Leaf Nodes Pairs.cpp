class Solution {
public:

    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj,
                    unordered_set<TreeNode*>& st) {

        if(root == NULL) {
            return;
        }

        if(root->left == NULL && root->right == NULL) {
            st.insert(root);
        }

        if(prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);

    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        makeGraph(root, NULL, adj, st);

        int count = 0;

        for(auto &leaf : st) {

            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(leaf);
            visited.insert(leaf);

            for(int level = 0; level <= distance; level++) {
                int size = que.size();
                while(size--) {
                    TreeNode* curr = que.front();
                    que.pop();

                    if(curr != leaf && st.count(curr)) {
                        count++;
                    }

                    for(auto &ngbr : adj[curr]) {
                        if(!visited.count(ngbr)) {
                            que.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};

class Solution {
public:

    vector<int> solve(TreeNode* root, int distance, int &goodLeafNodes) {
        if(!root) {
            return {0};
        }

        if(root->left == NULL && root->right == NULL) {
            return {1};
        }

        auto left_d  = solve(root->left, distance, goodLeafNodes);
        auto right_d = solve(root->right, distance, goodLeafNodes);

        for(int &l : left_d) {
            for(int &r : right_d) {
                if((l != 0 && r != 0) && l + r <= distance) {
                    goodLeafNodes++;
                }
            }
        }

        vector<int> curr_d;
        for(int &ld : left_d) {
            if(ld != 0 && ld + 1 <= distance) {
                curr_d.push_back(ld+1);
            }
        }

        for(int &rd : right_d) {
            if(rd != 0 && rd+1 <= distance) {
                curr_d.push_back(rd+1);
            }
        }

        return curr_d;

    }

    int countPairs(TreeNode* root, int distance) {
        int goodLeafNodes = 0;
        solve(root, distance, goodLeafNodes);

        return goodLeafNodes;
    }
};
