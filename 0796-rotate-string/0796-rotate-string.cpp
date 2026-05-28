class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
        int n = s.size();
        for(int i = 0; i < n; i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            if(rotated == goal) {
                return true;
            }
        }
        return false;
    }
};