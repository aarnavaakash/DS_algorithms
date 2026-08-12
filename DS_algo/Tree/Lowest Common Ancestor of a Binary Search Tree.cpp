class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;

        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while(true) {
            if(p->val < curr->val && q->val < curr->val)
                curr = curr->left;
            else if(p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            else
                break;
        }

        return curr;
    }
};
