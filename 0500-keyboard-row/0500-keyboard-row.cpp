class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";

        for (string word : words) {
            int row = 0;

            if (row1.find(word[0]) != string::npos)
                row = 1;
            else if (row2.find(word[0]) != string::npos)
                row = 2;
            else
                row = 3;

            bool valid = true;

            for (char c : word) {
                if (row == 1 && row1.find(c) == string::npos)
                    valid = false;

                if (row == 2 && row2.find(c) == string::npos)
                    valid = false;

                if (row == 3 && row3.find(c) == string::npos)
                    valid = false;
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};