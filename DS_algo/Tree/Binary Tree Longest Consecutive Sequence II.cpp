class Solution {
public:
    int maxL = 0;
    typedef pair<int, int> P;
    P find(TreeNode* root) {
        if(!root) return {0, 0};

        P p{1, 1};

        P l = find(root->left);
        P r = find(root->right);

        if(root->left) {
            if(root->val-root->left->val == 1) {
                p.first  = max(p.first, l.first+1);
            } else if(root->val-root->left->val == -1) {
                p.second = max(p.second, l.second+1);
            }
        }

        if(root->right) {
            if(root->val-root->right->val == 1) {
                p.first  = max(p.first, r.first+1);
            } else if(root->val-root->right->val == -1) {
                p.second = max(p.second, r.second+1);
            }
        }

        maxL = max({maxL, p.first, p.second, p.first+p.second-1});
        return p;
    }

    int longestConsecutive2(TreeNode * root) {
        maxL = 0;
        find(root);
        return maxL;
    }
};
