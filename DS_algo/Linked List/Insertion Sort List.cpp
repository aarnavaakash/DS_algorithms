class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* newHead = new ListNode(-1);
        ListNode* curr    = head;
        while(curr) {
            ListNode* prev    = newHead;
            ListNode* nxt     = newHead->next;
            while(nxt) {
                if(curr->val < nxt->val)
                    break;
                prev = nxt;
                nxt = nxt->next;
            }

            ListNode* temp = curr->next;
            curr->next     = nxt;
            prev->next     = curr;
            curr = temp;
        }
        return newHead->next;
    }
};
