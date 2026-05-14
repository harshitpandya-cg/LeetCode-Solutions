class Solution {
public:
    char findTheDifference(string s, string t) {
        int result = 0;
        for(char ch : s){
            result ^= ch;
        }
        for(char ch : t){
            result ^= ch;
        }
        return result;
    }
};