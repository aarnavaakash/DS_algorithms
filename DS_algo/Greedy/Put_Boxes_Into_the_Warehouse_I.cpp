class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int lastWareHouse = warehouse.size()-1;

        int Count = 0;
        for(int i = 0; i<boxes.size(); i++) {
            int h_box = boxes[i];

            int j = 0;

            while(j <= lastWareHouse && warehouse[j] >= h_box)
                j++;

            if(j == 0)
                break;

            if(j <= lastWareHouse) {
                lastWareHouse = j-2;
            } else {
                lastWareHouse--;
            }
            Count++;
        }
        return Count;
    }
};

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int m = boxes.size();
        int n = warehouse.size();

        int minVal = INT_MAX;

        for(int i = 0; i<n; i++) {
            minVal = min(minVal, warehouse[i]);
            warehouse[i] = minVal;
        }

        int i = 0, j = n-1;
        int count = 0;
        sort(boxes.begin(), boxes.end());
        while(i<m && j>=0) {
            if(warehouse[j] >= boxes[i]) {
                i++;
                j--;
                count++;
            } else {
                j--;
            }
        }
        return count;
    }
};
