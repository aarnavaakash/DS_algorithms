class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        for(int i = 1; i<left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for(int i = 1; i<=right-left; i++) {

            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;

        }

        return dummy->next;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* rightNode) {
        if(!head || !head->next || head == rightNode) {
            return head;
        }

        ListNode* last = reverse(head->next, rightNode);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftNode  = NULL;
        ListNode* leftPrev  = NULL;
        ListNode* rightNode = NULL;
        ListNode* rightNext = NULL;

        ListNode* curr = head;
        int c = 1;
        while(c < left) {
            leftPrev = curr;
            curr = curr->next;
            c++;
        }
        leftNode = curr;

        while(c < right) {
            curr = curr->next;
            c++;
        }

        rightNode = curr;
        rightNext = rightNode->next;

        ListNode* temp = reverse(leftNode, rightNode);

        if(leftPrev && leftPrev->next) {
            leftPrev->next->next = rightNext;
            leftPrev->next = temp;
        } else {

            head->next = rightNext;
            head = temp;
        }

        return head;

    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || !head->next)
            return head;

        stack<ListNode*> st;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 1; i<=left-1; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        for(int i = left; i<= right; i++) {
            st.push(curr);
            curr = curr->next;
        }

        ListNode* storeRightNext = st.top()->next;

        while(!st.empty()) {
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }

        prev->next = storeRightNext;
        return dummy->next;
    }
};
