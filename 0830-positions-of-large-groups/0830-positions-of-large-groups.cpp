class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        
        int start = 0;
        
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size() || s[i] != s[i - 1]) {
                if (i - start >= 3) {
                    ans.push_back({start, i - 1});
                }
                start = i;
            }
        }
        
        return ans;
    }
};