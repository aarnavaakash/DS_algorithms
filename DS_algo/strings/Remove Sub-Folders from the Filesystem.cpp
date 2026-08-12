class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;

        for(string& currFolder : folder) {
            bool isSubFolder = false;
            string tempFolder = currFolder;
            while(!currFolder.empty()) {
                size_t position = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0, position);

                if(st.find(currFolder) != st.end()) {

                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder) {
                result.push_back(tempFolder);
            }

        }

        return result;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> result;

        result.push_back(folder[0]);

        for(int i = 1; i < folder.size(); i++) {

            string currFolder = folder[i];
            string lastFolder = result.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0) {
                result.push_back(currFolder);
            }
        }

        return result;

    }
};
