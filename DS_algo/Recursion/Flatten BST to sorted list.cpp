class Solution
{
public:
    Node *flattenBST(Node *root) {
        if(!root) {
            return NULL;
        }

        Node* head   = flattenBST(root->left);
        root->left = NULL;
        root->right  = flattenBST(root->right);

        if (head) {
            Node *temp = head;
            while (temp->right) {
                temp = temp->right;
            }
            temp->right = root;
        } else {

            head = root;
        }

        return head;
    }
};

class Solution
{
public:
    Node* prev = NULL;
    Node *flattenBST(Node *root) {

        if(!root) {
            return NULL;
        }

        Node* head = flattenBST(root->left);
        root->left = NULL;
        if(prev) {
            prev->right = root;
            prev = root;
        } else {
            prev = root;
        }
        root->right = flattenBST(root->right);

        if(head == NULL) {
            return root;
        }

        return head;

    }
};
