class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> que;

        que.push(root);

        bool past = false;

        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if(node == NULL) {
                past = true;
            } else {
                if(past == true) {
                    return false;
                }

                que.push(node->left);
                que.push(node->right);
            }
        }

        return true;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* root, int i, int totalNodes) {
        if(root == NULL)
            return true;

        if(i > totalNodes)
            return false;

        return dfs(root->left, 2*i, totalNodes) &&
               dfs(root->right, 2*i + 1, totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);

        int i = 1;
        return dfs(root, i, totalNodes);
    }
};
