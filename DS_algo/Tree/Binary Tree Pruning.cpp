class Solution {
public:

    bool checkOne(TreeNode* root) {
        if(!root)
            return false;

        if(root->val == 1)
            return true;

        return checkOne(root->left) || checkOne(root->right);
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;

        pruneTree(root->left);
        pruneTree(root->right);

        if(!checkOne(root->left))  root->left = NULL;
        if(!checkOne(root->right)) root->right = NULL;

        if(!root->left && !root->right && root->val == 0)
            return NULL;
        return root;
    }
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;

        root->left  = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(!root->left && !root->right && root->val == 0)
            return NULL;

        return root;
    }
};
