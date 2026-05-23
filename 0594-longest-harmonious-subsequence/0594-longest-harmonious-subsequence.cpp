class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int longest = 0;
        for (auto it : freq) {
            int num = it.first;

            if (freq.count(num + 1)) {
                longest = max(longest, freq[num] + freq[num + 1]);
            }
        }
        return longest;
    }
};