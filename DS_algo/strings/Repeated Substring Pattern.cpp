************************************************ C++ ******************************************
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int l = 1; l <= n/2; l++) {

            if(n%l == 0) {
                int times = n/l;

                string pattern   = s.substr(0, l);
                string newStr = "";
                while(times--) {
                    newStr += pattern;
                }

                if(newStr == s)
                    return true;
            }

        }

        return false;
    }
};

************************************************ JAVA ******************************************
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();

        for (int l = n/2; l >= 1; l--) {

            if (n % l == 0) {

                int times = n/l;
                String pattern = s.substring(0, l);
                StringBuilder newStr = new StringBuilder();

                while(times > 0) {
                    newStr.append(pattern);
                    times--;
                }

                if (s.equals(newStr.toString())) {
                    return true;
                }

            }
        }

        return false;
    }
}
