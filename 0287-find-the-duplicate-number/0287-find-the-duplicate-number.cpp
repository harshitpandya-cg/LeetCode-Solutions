class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto num : freq) {
            if (num.second > 1) {
                return num.first;
            }
        }

        return -1;
    }
};