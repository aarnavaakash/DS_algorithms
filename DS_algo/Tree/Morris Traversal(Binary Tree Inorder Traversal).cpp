class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                pre = curr->left;

                while (pre->right != nullptr) {
                    pre = pre->right;
                }

                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }

        return result;
    }
};

public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        TreeNode curr = root;
        TreeNode pre;

        while (curr != null) {
            if (curr.left == null) {
                result.add(curr.val);
                curr = curr.right;
            } else {
                pre = curr.left;

                while (pre.right != null) {
                    pre = pre.right;
                }

                pre.right = curr;
                TreeNode temp = curr;
                curr = curr.left;
                temp.left = null;
            }
        }

        return result;
    }
}
