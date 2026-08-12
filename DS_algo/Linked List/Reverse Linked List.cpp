class Solution {
public:

    ListNode* reverseSolve(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode* last   = reverseSolve(head->next);
        head->next->next = head;
        head->next       = NULL;

        return last;

    }

    ListNode* reverseList(ListNode* head) {
        return reverseSolve(head);
    }
};

class Solution {
public:

    ListNode* reverseHelp(ListNode* head, ListNode* prev) {

        if(!head)
            return prev;

        ListNode* temp = head->next;
        head->next = prev;

        return reverseHelp(temp, head);
    }

    ListNode* reverseList(ListNode* head) {
        return reverseHelp(head, NULL);
    }
};

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
