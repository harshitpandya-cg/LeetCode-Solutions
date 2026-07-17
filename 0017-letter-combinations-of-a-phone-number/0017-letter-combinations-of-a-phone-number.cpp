class Solution {
public:
    vector<string> ans;
    string path;

    vector<string> mp = {
        "",     
        "",     
        "abc",  
        "def",  
        "ghi",  
        "jkl",  
        "mno",  
        "pqrs", 
        "tuv",  
        "wxyz"  
    };

    void solve(string &digits, int index) {
        if (index == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            path.push_back(ch);
            solve(digits, index + 1);
            path.pop_back();   
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        solve(digits, 0);
        return ans;
    }
};