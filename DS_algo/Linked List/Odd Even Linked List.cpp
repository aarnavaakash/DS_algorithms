class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* ODD  = head;
        ListNode* EVEN = head->next;

        ListNode* evenStart = head->next;

        while(EVEN != NULL && EVEN->next != NULL) {
            ODD->next  = EVEN->next;
            EVEN->next = EVEN->next->next;

            ODD  = ODD->next;
            EVEN = EVEN->next;
        }

        ODD->next = evenStart;

        return head;

    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;

        ListNode* start = head;
        ListNode* end   = head;
        int count = 1;
        while(end && end->next) {
            end = end->next;
            count++;
        }

        count /= 2;

        while(count--) {
            ListNode* startNext = start->next;
            start->next = start->next->next;

            end->next = startNext;

            start = start->next;
            end = end->next;
        }
        end->next = NULL;

        return head;
    }
};
