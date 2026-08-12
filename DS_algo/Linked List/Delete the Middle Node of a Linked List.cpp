class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prevSlow  = NULL;
        ListNode* slow      = head;
        ListNode* fast      = head;

        while(fast && fast->next) {
            prevSlow = slow;
            slow     = slow->next;

            fast     = fast->next->next;
        }

        if(prevSlow == NULL) {
            return NULL;
        }

        prevSlow->next = slow->next;
        delete(slow);

        return head;
    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;

        ListNode* slow      = head;
        ListNode* fast      = head->next->next;

        while(fast && fast->next) {
            slow     = slow->next;

            fast     = fast->next->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete(toDelete);

        return head;
    }
};
