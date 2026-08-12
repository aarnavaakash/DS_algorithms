class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;

        ListNode* curr = head;
        while(curr) {
            st.push(curr);
            curr = curr->next;
        }

        int k = st.size()/2;
        curr = head;
        while(k--) {
            ListNode* topNode = st.top();
            st.pop();

            ListNode* temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;
            curr = temp;
        }

        curr->next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseLL(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revHalf = reverseLL(slow);

        ListNode* curr = head;
        while(revHalf->next) {
            ListNode* tempFront = curr->next;
            curr->next          = revHalf;

            ListNode* tempBack  = revHalf->next;
            revHalf->next       = tempFront;

            revHalf             = tempBack;
            curr                = tempFront;
        }
    }
};

class Solution {
public:
    ListNode* curr;

    void solve(ListNode* head) {
        if(!head) {
            return;
        }

        solve(head->next);
        ListNode* tempn = curr->next;
        if(tempn == NULL) {
            return;
        } else if(head == curr) {
            head->next = NULL;
            return;
        }

        curr->next = head;
        head->next = tempn == head ? NULL : tempn;

        curr = tempn;
    }

    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};
