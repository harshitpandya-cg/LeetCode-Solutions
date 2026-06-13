class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;

        for(char ch : words[0]) {
            string temp = "";
            temp += ch;

            bool found = true;

            for(int j = 1; j < words.size(); j++) {
                int pos = words[j].find(ch);

                if(pos == string::npos) {
                    found = false;
                    break;
                }

                words[j].erase(pos, 1);
            }

            if(found) {
                res.push_back(temp);
            }
        }

        return res;
    }
};