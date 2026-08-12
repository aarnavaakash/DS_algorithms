class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        if(l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }

        return NULL;
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        if(start == end)
            return lists[start];

        if(start > end)
            return NULL;

        int mid = start + (end-start)/2;

        ListNode* l1 = partitionAndMerge(start, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, end, lists);

        return mergeTwoSortedLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        if(n == 0)
            return NULL;

        return partitionAndMerge(0, n-1, lists);

    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto lambda = [](ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> pq(lambda);

        for(ListNode* node : lists) {
            if(node != NULL) {
                pq.push(node);
            }
        }

        if(pq.empty()) {
            return NULL;
        }

        ListNode* head = pq.top();
        pq.pop();

        if(head->next != NULL) {
            pq.push(head->next);
        }

        ListNode* tail = head;

        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if(curr->next != NULL)
                pq.push(curr->next);
        }

        return head;

    }
};
