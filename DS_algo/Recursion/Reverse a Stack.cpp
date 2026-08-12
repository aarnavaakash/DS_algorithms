class Solution{
public:
    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }

        int top = St.top();
        St.pop();
        Reverse(St);

        stack<int> temp;
        while(!St.empty()) {
            temp.push(St.top());
            St.pop();
        }

        St.push(top);

        while(!temp.empty()) {
            St.push(temp.top());
            temp.pop();
        }
    }
};

class Solution{
public:

    void insertAtBottom(stack<int>& St, int element) {
        if(St.empty()) {
            St.push(element);
            return;
        }

        int cur_top_el = St.top();
        St.pop();
        insertAtBottom(St, element);
        St.push(cur_top_el);
    }

    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        int top = St.top();
        St.pop();

        Reverse(St);
        insertAtBottom(St, top);
    }
};
