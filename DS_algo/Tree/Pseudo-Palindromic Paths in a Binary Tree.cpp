class Solution {
public:
    int result = 0;

    void solve(TreeNode* root, vector<int>& temp) {
        if(root != NULL) {
            temp[root->val]++;

            if(root->left == NULL && root->right == NULL) {
                int oddFreq = 0;
                for(int i = 1; i <= 9; i++) {
                    if(temp[i]%2 != 0) {
                        oddFreq++;
                    }
                }

                result += oddFreq <= 1;
            }

            solve(root->left, temp);
            solve(root->right, temp);

            temp[root->val]--;

        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10, 0);

        solve(root, temp);
        return result;
    }
};

class Solution {
public:
    int result = 0;

    void solve(TreeNode* root, int temp) {
        if(root != NULL) {

            temp = temp ^ (1 << root->val);

            if(root->left == NULL && root->right == NULL) {
                if((temp & (temp - 1)) == 0) {
                    result++;
                }
            }

            solve(root->left, temp);
            solve(root->right, temp);

        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {

        solve(root, 0);
        return result;
    }
};
