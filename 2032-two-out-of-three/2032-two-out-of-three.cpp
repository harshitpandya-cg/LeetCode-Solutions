class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        set<int> s3(nums3.begin(), nums3.end());
        vector<int> ans;
        for (int i = 1; i <= 100; i++) {
            int count = 0;
            if (s1.count(i)) count++;
            if (s2.count(i)) count++;
            if (s3.count(i)) count++;
            if (count >= 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};