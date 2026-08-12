class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> que;
        que.push(root);

        vector<int> result;

        while(!que.empty()) {

            int n = que.size();
            int maxEl = INT_MIN;
            while(n--) {

                TreeNode* node = que.front();
                que.pop();

                maxEl = max(maxEl, node->val);

                if(node->left)
                    que.push(node->left);

                if(node->right)
                    que.push(node->right);
            }

            result.push_back(maxEl);

        }

        return result;
    }
};

class Solution {
public:
    vector<int> result;

    void DFS(TreeNode* root, int depth) {
        if(!root)
            return;

        if(depth == result.size()) {
            result.push_back(root->val);
        } else {
            result[depth] = max(result[depth], root->val);
        }

        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }

    vector<int> largestValues(TreeNode* root) {
        DFS(root, 0);
        return result;
    }
};
