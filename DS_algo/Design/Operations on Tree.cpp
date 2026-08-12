class LockingTree {
public:
    unordered_map<int, vector<int>> descendents;
    vector<vector<int>> Node;

    int n;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        Node.resize(n, vector<int>(2, -1));

        Node[0][0] = -1;
        for(int i = 1; i<n; i++) {
            Node[i][0] = parent[i];
            descendents[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if(Node[num][1] != -1) return false;

        Node[num][1] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if(Node[num][1] != user) return false;

        Node[num][1] = -1;
        return true;
    }

    void checkDescendents(int num, bool& atleastOne) {
        if(descendents.count(num) == 0 || descendents[num].size() == 0)
            return;

        for(int& x : descendents[num]) {
            if(Node[x][1] != -1) {
                atleastOne = true;
                return;
            }
            checkDescendents(x, atleastOne);
        }
    }

    bool IsAnyAncestorLocked(int& num) {
        if(num == -1)
            return false;

        return Node[num][1] != -1 || IsAnyAncestorLocked(Node[num][0]);
    }

    void unlockDescendents(int num) {
        if(descendents.count(num) == 0 || descendents[num].size() == 0)
            return;

        for(int& x : descendents[num]) {
            Node[x][1] = -1;
            unlockDescendents(x);
        }
    }

    bool upgrade(int num, int user) {

        if(Node[num][1] != -1) return false;

        bool atleastOne = false;
        checkDescendents(num, atleastOne);

        if(!atleastOne) return false;

        if(IsAnyAncestorLocked(Node[num][0])) return false;

        unlockDescendents(num);
        Node[num][1] = user;
        return true;
    }
};
