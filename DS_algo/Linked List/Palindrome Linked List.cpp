class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;

        ListNode* curr = head;
        while(curr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0;
        int j = temp.size()-1;

        while(i < j) {
            if(temp[i] != temp[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revhead = reverseList(slow);
        prev->next = NULL;

        while(revhead != NULL && head != NULL) {
            if(revhead->val != head->val) {
                return false;
            }

            revhead = revhead->next;
            head = head->next;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            fast = fast->next->next;

            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        if (fast)
            slow = slow->next;

        while(prev && slow) {
            if(prev->val != slow->val) {
                return false;
            }

            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};

class Solution {
public:
    ListNode* curr;

    bool solve(ListNode* head) {
        if(!head)
            return true;

        if(!solve(head->next) || head->val != curr->val) {
            return false;
        }

        curr = curr->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        curr = head;

        return solve(head);
    }
};
