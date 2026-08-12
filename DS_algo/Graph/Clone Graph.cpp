class Solution {
public:

    void DFS(Node* node, Node* clone_node, vector<Node*>& visited) {
        visited[node->val] = clone_node;

        for(Node* x : node->neighbors) {
            if(visited[x->val] == NULL) {
                Node* clone = new Node(x->val);
                clone_node->neighbors.push_back(clone);
                DFS(x, clone, visited);
            } else {
                clone_node->neighbors.push_back(visited[x->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;

        Node* clone_node = new Node(node->val);

        vector<Node*> visited(101, NULL);

        visited[node->val] = clone_node;

        DFS(node, clone_node, visited);

        return clone_node;
    }
};

class Solution {
public:

    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* clone_node) {

        for(Node* n : node->neighbors) {

            if(mp.find(n) == mp.end()) {

                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(n, clone);

            } else {

                clone_node->neighbors.push_back(mp[n]);

            }

        }

    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;

        mp.clear();

        Node* clone_node = new Node(node->val);

        mp[node] = clone_node;

        DFS(node, clone_node);

        return clone_node;
    }
};

class Solution {
public:
    void BFS(queue<Node*>& que, vector<Node*>& visited) {
        while(!que.empty()) {
            Node* node = que.front();
            que.pop();

            for(Node* x : node->neighbors) {
                if(visited[x->val] == NULL) {
                    Node* clone = new Node(x->val);
                    visited[node->val]->neighbors.push_back(clone);

                    visited[x->val] = clone;
                    que.push(x);
                } else {
                    visited[node->val]->neighbors.push_back(visited[x->val]);

                }
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;

        Node* clone_node = new Node(node->val);

        vector<Node*> visited(101, NULL);
        visited[node->val] = clone_node;

        queue<Node*> que;
        que.push(node);

        BFS(que, visited);

        return clone_node;
    }
};

class Solution {
public:

    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* clone_node) {

        for(Node* n : node->neighbors) {

            if(mp.find(n) == mp.end()) {

                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(n, clone);

            } else {

                clone_node->neighbors.push_back(mp[n]);

            }

        }

    }

    void BFS(queue<Node*> &que) {

        while(!que.empty()) {

            Node* node = que.front();
            Node* clone_node = mp[node];
            que.pop();

            for(Node* n : node->neighbors) {

                if(mp.find(n) == mp.end()) {

                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);

                    que.push(n);

                } else {

                    clone_node->neighbors.push_back(mp[n]);

                }

            }

        }

    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;

        mp.clear();

        Node* clone_node = new Node(node->val);

        mp[node] = clone_node;

        queue<Node*> que;
        que.push(node);
        BFS(que);

        return clone_node;
    }
};
