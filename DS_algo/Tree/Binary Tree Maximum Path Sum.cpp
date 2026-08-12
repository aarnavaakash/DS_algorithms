class Solution {
public:

    int maxSum;

    int solve(TreeNode* root) {
        if(root == NULL)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_hi_milgaya_answer = l + r + root->val;

        int koi_ek_acha = max(l, r) + root->val;

        int only_root_acha = root->val;

        maxSum = max({maxSum, neeche_hi_milgaya_answer, koi_ek_acha, only_root_acha});

        return max(koi_ek_acha, only_root_acha);

    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);

        return maxSum;

    }
};
