class Solution {
public:
    int addOne(ListNode* head) {
        if(!head)
            return 1;

        int val = head->val + addOne(head->next);

        head->val = val%10;
        return val/10;
    }
    ListNode * plusOne(ListNode * head) {
        int carry = addOne(head);

        if(carry == 1) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};
