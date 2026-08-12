class Solution {
public:
    vector<int> arr;
    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }

    int getRandom() {
        int n       = arr.size();
        int r_index = rand()%n;
        return arr[r_index];
    }
};

class Solution {
public:
    ListNode* temp;
    Solution(ListNode* head) {
        temp = head;
    }

    int getRandom() {
        int res;
        ListNode* curr = temp;
        int size = 1;
        while(curr) {

            if(rand()%size == 0)
                res = curr->val;
            curr = curr->next;
            size++;
        }
        return res;
    }
};
